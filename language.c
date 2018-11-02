
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

void language_set_print(t_language* language, void (*print)(void* a)){
	if(language->print != NULL){
		free(language->print);
	}
	language->print = print;
}

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
				elements_count, language->elements_size);
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

//Tested
bool equals_char(void* c1, void* c2){
	return *((char*) c1) == *((char*) c2);
}

//Tested
bool equals_int8(void* c1, void* c2){
	return (*((int8_t*) c1)) == (*((int8_t*) c2));
}

//Tested
bool equals_words_char(const char* c1,const char* c2){
	return strcmp(c1, c2) == 0;
}

void generate(t_language* language){
	int lenght_max = 4; //Hardcoded;

	//Inicializations
	void* elements = language->elements;
	void* last_element = language->last_element;
	size_t size = language->elements_size;
	size_t count = language->elements_count;

	bool equals(void* a,void* b){
		(*(language->equals))(a,b);
	};

	void print(void* a){
		(*(language->print)) (a);
	}

	int length_current = 1;
	void* word = malloc(size);
	int* indexes = malloc(length_current * sizeof(int));
	for (int i = 0; i < length_current; indexes[i] = 0, ++i);
	
	while(length_current < lenght_max){

		// printf("Lenght: %d\n", length_current); //debug
		for(int i = 0; i < count; i++){
			memcpy(word + (length_current-1) * size,
					elements + i * size,
					size);

			for (int i = 0; i < length_current; ++i){
				print(word + i);
				printf("\t");
			}
			printf("\n");
		}
		
		//Check if is the max word
		bool is_element_to_change = true;
		int elements_to_change = 0;

		for (int i = 0; i < length_current && is_element_to_change; ++i){

			is_element_to_change = equals(word + (length_current - 1 - i ) * size, last_element);

			if(is_element_to_change){
				elements_to_change++;
			}
		}

		// printf("%d elements to change of %d\n", elements_to_change, length_current);

		if (elements_to_change == length_current){
			printf("Is the last word with %d lenght\n", length_current);
			length_current++;

			free(word);
			free(indexes);

			word = malloc(length_current);
			indexes = malloc(length_current * sizeof(int));

			for (int i = 0; i < length_current; ++i){
				memcpy(word + i * size,
					elements,
					size);

				indexes[i] = 0;
			}
		}

		else{

			//debug
			printf("Indexes:");
			for (int i = 0; i < length_current; ++i){
				printf("\t%d", indexes[i]);		
			}
			printf("\n");
			// debug

			// printf("There are %d to change of %d\n", elements_to_change, length_current);//debug

			//Replace the elements which are equals to last_element
			for (int i = 0; i < elements_to_change; ++i){
				memcpy(word + (length_current - 1 - i) * size,
					elements,
					size);
				indexes[length_current - 1 - i] = 0;
			}

			//element++
			printf("Change element at index %d by %d\n",
				length_current - elements_to_change - 1,
				*(int8_t*)(elements+ (indexes[length_current - elements_to_change - 1] + 1) * size));

			memcpy(word + (length_current - elements_to_change - 1) * size,
				elements+ (indexes[length_current - elements_to_change - 1] + 1) * size,
				size);

			indexes[length_current - elements_to_change - 1] += 1;
			getchar();
		}
	}
}
