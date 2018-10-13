
#include "alphabet.h"

//Tested
t_alphabet* alphabet_create(){
	t_alphabet* alphabet = (t_alphabet*) malloc(sizeof(t_alphabet));
	alphabet->elements = NULL;
	alphabet->elements_count = 0;
	alphabet->elements_size = 0;
	alphabet->last_element = NULL;
	alphabet->equals = NULL;
	return alphabet;
}

//Tested
void alphabet_destroy(t_alphabet* alphabet){
	if(alphabet != NULL){
		free(alphabet->elements);
		free(alphabet);
	}
	alphabet = NULL;
}

//Tested
void alphabet_set_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size){
	if(alphabet->elements != NULL){
		free(alphabet->elements);
	}

	//Filter elements
	void* filtred_elements = malloc(elements_count * elements_size);
	size_t filtred_elements_count = 0;
	bool filter_ok;

	for(int i = 0; i < elements_count; i++){
		filter_ok = false;

		for(int j = 0; j < filtred_elements_count && !filter_ok; j++){
			filter_ok =  (*(alphabet->equals))
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

	alphabet->elements = filtred_elements;
	alphabet->elements_count = filtred_elements_count;
	alphabet->elements_size = elements_size;
	alphabet->last_element = malloc(elements_size);
	memcpy(alphabet->last_element,
			filtred_elements + elements_size*(filtred_elements_count-1),
			elements_size);
}

//Tested
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size){

	if(alphabet->elements_count == 0){
		alphabet_set_element(alphabet, elements, elements_count, elements_size);
	}

	else if(alphabet->elements_size == elements_size){

		alphabet->elements = realloc( alphabet->elements,
				(alphabet->elements_count + elements_count) * elements_size);

		bool filter_ok;

		//Filter the new elements with himself
		for(int i = 0; i < elements_count; i++){
			filter_ok = false;

			for(int j = 0; j < alphabet->elements_count && !filter_ok; j++){
				filter_ok =  (*(alphabet->equals))
						(elements + i*elements_size, alphabet->elements + j*elements_size);
			}

			if(!filter_ok){
				memcpy( alphabet->elements + (alphabet->elements_count * elements_size),
						elements + i*elements_size,
						elements_size);
				alphabet->elements_count++;
			}
		}

		alphabet->elements = realloc( alphabet->elements,
				alphabet->elements_count * elements_size);
		free(alphabet->last_element);
		alphabet->last_element = malloc(elements_size);
		memcpy(alphabet->last_element,
				alphabet->elements + elements_size * (alphabet->elements_count - 1),
				elements_size);
	}

	else{
		printf("The size of elements <%d> should be equals to the size of existing elements <%d>\n",
				elements_count, alphabet->elements_size);
	}
}

//Tested
void alphabet_set_equal(t_alphabet* alphabet, bool(*equal)(void*,void*)){
	alphabet->equals = equal;
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

//Tested
char* element_get_upCase(){
	char* elements = malloc(LETTERS_COUNT);
	for(int i = 0; i < LETTERS_COUNT; elements[i] = 'A' + i, i++);
	return elements;
}

//Tested
char* element_get_lowCase(){
	char* elements = malloc(LETTERS_COUNT);
	for(int i = 0; i < LETTERS_COUNT; elements[i] = 'a' + i, i++);
	return elements;
}

//Tested
char* element_get_numbers(){
	char* elements = malloc(10);
	for(int i = 0; i < 10; elements[i] = '0' + i, i++);
	return elements;
}
