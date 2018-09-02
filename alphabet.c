
#include "alphabet.h"

//Tested
t_alphabet* alphabet_create(){
	t_alphabet* alphabet = (t_alphabet*) malloc(sizeof(t_alphabet));
	alphabet->elements = NULL;
	alphabet->elements_count = 0;
	alphabet->elements_size = 0;
	alphabet->last_element = NULL;
	return alphabet;
}

//Tested
void alphabet_destroy(t_alphabet* alphabet){
	if(alphabet != NULL){
		free(alphabet->elements);
		free(alphabet);
		alphabet = NULL;
	}
}

//Tested
void alphabet_set_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size){
	if(alphabet->elements != NULL){
		free(alphabet->elements);
	}

	alphabet->elements = elements;
	alphabet->elements_count = elements_count;
	alphabet->elements_size = elements_size;
	alphabet->last_element = malloc(elements_size);
	memcpy(alphabet->last_element,
			elements + elements_size*(elements_count-1),
			elements_size);
}


//Tested
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size){

	if(alphabet->elements_count == 0){
		alphabet->elements = elements;
		alphabet->elements_count = elements_count;
		alphabet->elements_size = elements_size;
		alphabet->last_element = malloc(elements_size);
		memcpy(alphabet->last_element,
				elements + elements_size*(elements_count-1),
				elements_size);
	}

	else if(alphabet->elements_size == elements_size ){
		size_t old_size = alphabet->elements_count * alphabet->elements_size;
		size_t new_size = elements_count * elements_size;
		alphabet->elements = realloc(alphabet->elements, old_size + new_size );
		memcpy(alphabet->elements + old_size, elements, new_size);
		alphabet->elements_count += elements_count;
		alphabet->elements_size = elements_size;
		alphabet->last_element = malloc(elements_size);
		memcpy(alphabet->last_element,
				elements + elements_size*(elements_count-1),
				elements_size);
	}

	else{
		printf("The size of elements <%d> should be equals to the size of existing elements <%d>\n", elements_count, alphabet->elements_size);
	}

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

