
#include "alphabet.h"

void alphabet_remove_all_elements(t_alphabet* alphabet){
	free(alphabet->elements);
	alphabet->elements = NULL;
}

char* get_letters(e_letters_group group){
	char* letters = NULL;
	switch(group){
	case LOW:
		letters = (char*) malloc( sizeof(char) * LETTERS_COUNT);
		for(int i = 0; i < LETTERS_COUNT; i++){
			letters[i] = 'a' + i;
		}
		break;

	case CAPITAL:
		letters = (char*) malloc( sizeof(char) * LETTERS_COUNT);
		for(int i = 0; i < LETTERS_COUNT; i++){
			letters[i] = 'A' + i;
		}
		break;

	case NUMBERS:
		letters = (char*) malloc( sizeof(char) * 10);
		for(int i = 0; i < 10; i++){
			letters[i] = '0' + i;
		}
		break;

	case ALL:
		letters = (char*) malloc( sizeof(char) * (LETTERS_COUNT*2 + 10) );
		for(int i = 0; i < LETTERS_COUNT; i++){
			letters[i] = 'a' + i;
		}
		for(int i = 0; i < LETTERS_COUNT; i++){
			letters[LETTERS_COUNT + i] = 'A' + i;
		}
		for(int i = 0; i < 10; i++){
			letters[LETTERS_COUNT*2 + i] = '0' + i;
		}
		break;

	default: break;
	}

	return letters;
}

char* get_ascii(){
	char* all_ascii = (char*) malloc( sizeof(char) * 10);
	for(char i = 0; i < 256; i++){
		all_ascii[i] = '0' + i;
	}
	return all_ascii;
}

t_alphabet* alphabet_create(){
	t_alphabet* alphabet = (t_alphabet*) malloc(sizeof(t_alphabet));
	alphabet->elements = NULL;
	alphabet->elements_count = 0;
	return alphabet;
}

void alphabet_add_elements(t_alphabet* alphabet, char* elements, size_t new_elements_count){
	size_t size_all_elements = alphabet->elements_count + new_elements_count;
	void* all_elements = malloc(size_all_elements);
	memset(all_elements, 0, size_all_elements);
	memcpy(all_elements, alphabet->elements, alphabet->elements_count);
	memcpy(all_elements + alphabet->elements_count, elements, new_elements_count);

	free(alphabet->elements);
	alphabet->elements_count += new_elements_count;
}
