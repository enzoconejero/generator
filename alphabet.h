
#ifndef ALPHABET_H
#define ALPHABET_H

#include "commons-includes.h"

#define LETTERS_COUNT ('z' - 'a' + 1)

typedef struct{
	size_t elements_count;
	char* elements;
}t_alphabet;

typedef enum{
	ALL,
	LOW,
	CAPITAL,
	NUMBERS
}e_letters_group;

char* get_letters(e_letters_group group);
char* get_ascii();
void alphabet_remove_all_elements(t_alphabet* alphabet);

//For generichs languajes
t_alphabet* alphabet_create();
void alphabet_add_elements(t_alphabet* alphabet, char* elements, size_t new_elements_count);

#endif
