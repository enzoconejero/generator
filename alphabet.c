
#include "alphabet.h"

//Tested
t_alphabet* alphabet_create(){
	t_alphabet* alphabet = (t_alphabet*) malloc(sizeof(t_alphabet));
	alphabet->elements = NULL;
	alphabet->elements_count = 0;
	alphabet->elements_size = 0;
	alphabet->last_element = '\0';
	return alphabet;
}

void alphabet_destroy(t_alphabet* alphabet){
	if(alphabet != NULL){
		free(alphabet->elements);
		free(alphabet);
		alphabet = NULL;
		printf("%d\n", (int)alphabet);
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
}

//Tested
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size){
	size_t old_size = alphabet->elements_count * alphabet->elements_size;
	size_t new_size = elements_count * elements_size;
	alphabet->elements = realloc(alphabet->elements, old_size + new_size );
	memcpy(alphabet->elements + old_size, elements, new_size);
}

char* element_get_upCase(){
	char* elements = malloc(LETTERS_COUNT);
	for(int i = 0; i < LETTERS_COUNT; elements[i] = 'A' + i, i++);
	return elements;
}

char* element_get_lowCase(){
	char* elements = malloc(LETTERS_COUNT);
	for(int i = 0; i < LETTERS_COUNT; elements[i] = 'a' + i, i++);
	return elements;
}

char* element_get_numbers(){
	char* elements = malloc(10);
	for(int i = 0; i < 10; elements[i] = '0' + i, i++);
	return elements;
}



//
//void elements_get_upCase(t_alphabet* alphabet){
//	char* elements = malloc(LETTERS_COUNT);
//	memset(elements, 0, LETTERS_COUNT);
//	for(int i = 0; i < LETTERS_COUNT; i++){
//		elements[i] = 'a'+i;
//	}
//
//}
//
//void elements_get_lowCase(t_alphabet* alphabet){
//
//}
//
//void elements_get_numbers(t_alphabet* alphabet){
//
//}
//
//void elements_get_alphaNumeric(t_alphabet* alphabet){
//
//}
//
//void elements_get_all_letters(t_alphabet* alphabet){
//
//}
//
//void elements_get_ascii(t_alphabet* alphabet){
//
//}
