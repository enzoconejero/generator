
#ifndef ALPHABET_H
#define ALPHABET_H

#include "commons-includes.h"

typedef struct{
	size_t elements_count;
	size_t elements_size;
	void* elements;
	char last_element;
}t_alphabet;

//typedef enum{
//	ALL,
//	LOW,
//	CAPITAL,
//	NUMBERS
//}e_letters_group;
//
//char* get_letters(e_letters_group group);
//char* get_ascii();
//void alphabet_remove_all_elements(t_alphabet* alphabet);
//
////For generichs languajes

//Creation and destruction
t_alphabet* alphabet_create();
void alphabet_destroy(t_alphabet* alphabet);

//Set and Add general elements
void alphabet_set_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);


//Set letters alphabet
void alphabet_set_lowCase(t_alphabet* alphabet);
void alphabet_set_upCase(t_alphabet* alphabet);

//void alphabet_set_elements(t_alphabet* alphabet, char* elements, size_t element);
//void alphabet_add_elements(t_alphabet* alphabet, char* elements, size_t element);
//void alphabet_remove_elements(t_alphabet* alphabet);
//void alphabet_remove_and_free_elements(t_alphabet* alphabet);
//
//void elements_get_upCase(t_alphabet* alphabet);
//void elements_get_lowCase(t_alphabet* alphabet);
//void elements_get_numbers(t_alphabet* alphabet);
//void elements_get_alphaNumeric(t_alphabet* alphabet);
//void elements_get_all_letters(t_alphabet* alphabet);
//void elements_get_ascii(t_alphabet* alphabet);


#endif
