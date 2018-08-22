
#ifndef ALPHABET_H
#define ALPHABET_H

#include "commons-includes.h"

#define LETTERS_COUNT ('z' - 'a' + 1)

//using ADT cause it may change
typedef char t_element;

typedef struct{
	size_t total;
	t_element* elements;
}t_char_alphabet;

t_char_alphabet* create_char_alphabet();
void alphabet_add_elements(t_char_alphabet* alphabet, t_element* new_elements, size_t new_elements_count);
void alphabet_remove_all_elements(t_char_alphabet* alphabet);

typedef enum{
	ALL,
	LOW,
	CAPITAL,
	NUMBERS
}e_letters_group;

t_element* get_letters(e_letters_group group);
t_element* ascii();

#endif
