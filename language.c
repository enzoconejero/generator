
#include "language.h"

//Tested
t_language* language_create(){
	t_language* language = (t_language*) malloc(sizeof(t_language));
	language->elements = NULL;
	language->elements_count = 0;
	language->elements_size = 0;
	language->last_element = NULL;
	language->equals = NULL;
	language->print = NULL;
	return language;
}

//Tested
void language_destroy(t_language* language){
	free(language->elements);
	free(language->last_element);
	free(language);
}

//Tested
void language_set_print(t_language* language, void (*print)(t_gcb*)){
	language->print = print;
}

void language_set_filter(t_language* language,bool (*filter)(t_gcb*)){
	language->filter = filter;
}

//Tested
void language_set_element(t_language* language, void* elements, size_t elements_count, size_t elements_size){
	if(language->elements != NULL){
		free(language->elements);
	}

	//Filter elements
	void* filtred_elements = malloc(elements_count * elements_size);
	size_t filtred_elements_count = 0;
	bool filter_ok;

	for(int i = 0; i < elements_count; i++){
		filter_ok = false;

		for(int j = 0; j < filtred_elements_count && !filter_ok; j++){
			filter_ok =  (*(language->equals))
					(elements + i*elements_size, filtred_elements + j*elements_size);
		}

		if(!filter_ok){
			memcpy(filtred_elements + filtred_elements_count*elements_size,
					elements + i*elements_size,
					elements_size);
			filtred_elements_count++;
		}
	}

	filtred_elements = realloc(filtred_elements, elements_size * elements_count);

	language->elements = filtred_elements;
	language->elements_count = filtred_elements_count;
	language->elements_size = elements_size;
	language->last_element = malloc(elements_size);
	memcpy(language->last_element,
			filtred_elements + elements_size*(filtred_elements_count-1),
			elements_size);
}

//Tested
void language_add_element(t_language* language, void* elements, size_t elements_count, size_t elements_size){

	if(language->elements_count == 0){
		language_set_element(language, elements, elements_count, elements_size);
	}

	else if(language->elements_size == elements_size){

		language->elements = realloc( language->elements,
				(language->elements_count + elements_count) * elements_size);

		bool filter_ok;

		//Filter the new elements with himself
		for(int i = 0; i < elements_count; i++){
			filter_ok = false;

			for(int j = 0; j < language->elements_count && !filter_ok; j++){
				filter_ok =  (*(language->equals))
						(elements + i*elements_size, language->elements + j*elements_size);
			}

			if(!filter_ok){
				memcpy( language->elements + (language->elements_count * elements_size),
						elements + i*elements_size,
						elements_size);
				language->elements_count++;
			}
		}

		language->elements = realloc( language->elements,
				language->elements_count * elements_size);
		free(language->last_element);
		language->last_element = malloc(elements_size);
		memcpy(language->last_element,
				language->elements + elements_size * (language->elements_count - 1),
				elements_size);
	}

	else{
		printf("The size of elements <%d> should be equals to the size of existing elements <%d>\n",
				(int)elements_count, (int)language->elements_size);
	}
}

//Tested
void language_set_equal(t_language* language, bool(*equal)(void*,void*)){
	language->equals = equal;
}

void* language_get_element_at(t_language* language, int index){
	void* element = malloc(language->elements_size);
	memcpy( element,
		language->elements + index * language->elements_size,
		language->elements_size);

	return element;
}

int language_indexOf(t_language* language, void* element){
	bool is_equal = false;
	for(int i = 0; i < language->elements_count; i++){
		is_equal = (*(language->equals)) (language->elements + i * language->elements_size, element);
		if(is_equal){
			return i;
		}
	}
	return -1;
}

bool language_has_element(t_language* language, void* element){
	bool is_equal = false;
	for(int i = 0; i < language->elements_count; i++){
		is_equal = (*(language->equals)) (language->elements + i * language->elements_size, element);
		if(is_equal){
			return true;
		}
	}
	return false;	
}

bool language_is_valid_word(t_language* language, void* word, size_t length){
	for(int i = 0; i < length; i++){
		if( language_indexOf(language ,word + i * language->elements_size) == -1){
			return false;
		}
	}

	t_gcb* gcb = gcb_create(language);
	gcb->word = word;
	gcb->current_length = length;
	bool is_valid = (*(language->filter)) (gcb);
	gcb_free(gcb);
	return is_valid;
}
