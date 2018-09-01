
#include "alphabet.h"

//void alphabet_remove_all_elements(t_alphabet* alphabet){
//	free(alphabet->elements);
//	alphabet->elements = NULL;
//}
//
//char* get_letters(e_letters_group group){
//	char* letters = NULL;
//	switch(group){
//	case LOW:
//		letters = (char*) malloc( sizeof(char) * LETTERS_COUNT);
//		for(int i = 0; i < LETTERS_COUNT; i++){
//			letters[i] = 'a' + i;
//		}
//		break;
//
//	case CAPITAL:
//		letters = (char*) malloc( sizeof(char) * LETTERS_COUNT);
//		for(int i = 0; i < LETTERS_COUNT; i++){
//			letters[i] = 'A' + i;
//		}
//		break;
//
//	case NUMBERS:
//		letters = (char*) malloc( sizeof(char) * 10);
//		for(int i = 0; i < 10; i++){
//			letters[i] = '0' + i;
//		}
//		break;
//
//	case ALL:
//		letters = (char*) malloc( sizeof(char) * (LETTERS_COUNT*2 + 10) );
//		for(int i = 0; i < LETTERS_COUNT; i++){
//			letters[i] = 'a' + i;
//		}
//		for(int i = 0; i < LETTERS_COUNT; i++){
//			letters[LETTERS_COUNT + i] = 'A' + i;
//		}
//		for(int i = 0; i < 10; i++){
//			letters[LETTERS_COUNT*2 + i] = '0' + i;
//		}
//		break;
//
//	default: break;
//	}
//
//	return letters;
//}
//
//char* get_ascii(){
//	char* all_ascii = (char*) malloc( sizeof(char) * 10);
//	for(char i = 0; i < 256; i++){
//		all_ascii[i] = '0' + i;
//	}
//	return all_ascii;
//}
//
//t_alphabet* alphabet_create(){
//	t_alphabet* alphabet = (t_alphabet*) malloc(sizeof(t_alphabet));
//	alphabet->elements = NULL;
//	alphabet->elements_count = 0;
//	return alphabet;
//}
//
//void alphabet_add_elements(t_alphabet* alphabet, char* elements, size_t new_elements_count){
//	size_t size_all_elements = alphabet->elements_count + new_elements_count;
//	char* all_elements = malloc(size_all_elements);
//	memset(all_elements, 0, size_all_elements);
//	memcpy(all_elements, alphabet->elements, alphabet->elements_count);
//	memcpy(all_elements + alphabet->elements_count, elements, new_elements_count);
//
//	free(alphabet->elements);
//	alphabet->elements_count += new_elements_count;
//}

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

void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size){
	size_t old_size = alphabet->elements_count * alphabet->elements_size;
	size_t new_size = elements_count * elements_size;
	alphabet->elements = realloc(alphabet->elements, old_size + new_size );
	memcpy(alphabet->elements + old_size, elements, new_size);
}

//void alphabet_set_elements(t_alphabet* alphabet, char* elements, size_t element_count){
//	if(alphabet != NULL){
//		if(alphabet->elements == NULL){
//			free(alphabet->elements);
//		}
//		//Repeated logic in set_elements
//		alphabet->elements = (char*)malloc(element_count);
//		memset(alphabet->elements, 0, element_count);
//		memcpy(alphabet->elements, elements, element_count);
//
//		alphabet->elements_count = element_count;
//		alphabet->last_element = alphabet->elements[alphabet->elements_count - 1];
//
//	}
//	else{
//		printf("[ERROR]: El alfabeto no existe\n");
//		exit(0);
//	}
//}
//
//void alphabet_add_elements(t_alphabet* alphabet, char* elements, size_t element_count){
//	if(alphabet != NULL){
//		if(alphabet->elements == NULL){
//			//Repeated logic in set_elements
//			alphabet->elements = (char*)malloc(element_count);
//			memset(alphabet->elements, 0, element_count);
//			memcpy(alphabet->elements, elements, element_count);
//
//			alphabet->elements_count = element_count;
//			alphabet->last_element = alphabet->elements[alphabet->elements_count - 1];
//		}
//		else{
//			//Must check te characters do not repeat
//			size_t new_element_count = alphabet->elements_count + element_count;
//			alphabet->elements = realloc(alphabet->elements, new_element_count);
//			memset(alphabet->elements + alphabet->elements_count, 0, element_count);
//			memcpy(alphabet->elements + alphabet->elements_count, elements, element_count);
//
//			alphabet->elements_count += element_count;
//			alphabet->last_element = alphabet->elements[alphabet->elements_count-1];
//		}
//
//	}
//	else{
//		printf("[ERROR]: El alfabeto no existe\n");
//		exit(0);
//	}
//}
//
//void alphabet_remove_elements(t_alphabet* alphabet){
//	if(alphabet != NULL){
//		alphabet->elements = NULL;
//	}
//	else{
//		printf("[ERROR]: El alfabeto no existe\n");
//		exit(0);
//	}
//}
//
//void alphabet_remove_and_free_elements(t_alphabet* alphabet){
//	if(alphabet != NULL){
//		free(alphabet->elements);
//		alphabet->elements = NULL;
//	}
//	else{
//		printf("[ERROR]: El alfabeto no existe\n");
//		exit(0);
//	}
//}
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
