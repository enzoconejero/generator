
#include "alphabet.h"

t_char_alphabet* create_char_alphabet(){
	t_char_alphabet* alphabet = (t_char_alphabet*) malloc(sizeof(t_char_alphabet));
	alphabet->elements = NULL;
	alphabet->total = 0;
	return alphabet;
}

void alphabet_add_elements(t_char_alphabet* alphabet, t_element* new_elements, size_t new_elements_count){
	size_t size_all_elements = sizeof(t_element) * (alphabet->total + new_elements_count);
	t_element* all_elements = (t_element*) malloc(size_all_elements);
	memset(all_elements, 0, size_all_elements);
	memcpy(all_elements, alphabet->elements, sizeof(t_element) * alphabet->total);
	memcpy(all_elements + sizeof(t_element) * alphabet->total, new_elements, sizeof(t_element) * new_elements_count);

	free(alphabet->elements);
	alphabet->total += new_elements_count;
	alphabet->elements = all_elements;
	//It should be doing with a realloc
}

void alphabet_remove_all_elements(t_char_alphabet* alphabet){
//	free(alphabet->elements);
	alphabet->elements = NULL;
}

t_element* get_letters(e_letters_group group){
	t_element* letters = NULL;
	switch(group){
	case LOW:
		letters = (t_element*) malloc( sizeof(t_element) * LETTERS_COUNT);
		for(int i = 0; i < LETTERS_COUNT; i++){
			letters[i] = 'a' + i;
		}
		break;

	case CAPITAL:
		letters = (t_element*) malloc( sizeof(t_element) * LETTERS_COUNT);
		for(int i = 0; i < LETTERS_COUNT; i++){
			letters[i] = 'A' + i;
		}
		break;

	case NUMBERS:
		letters = (t_element*) malloc( sizeof(t_element) * 10);
		for(int i = 0; i < 10; i++){
			letters[i] = '0' + i;
		}
		break;

	case ALL:
		letters = (t_element*) malloc( sizeof(t_element) * (LETTERS_COUNT*2 + 10) );
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

t_element* ascii(){
	t_element* all_ascii = (t_element*) malloc( sizeof(t_element) * 10);
	for(char i = 0; i < 256; i++){
		all_ascii[i] = '0' + i;
	}
	return all_ascii;
}
