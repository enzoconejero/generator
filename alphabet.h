
#ifndef ALPHABET_H
#define ALPHABET_H

#include "commons-includes.h"

typedef struct{
	size_t elements_count;
	size_t elements_size;
	void* elements;
	char last_element;
}t_alphabet;


/*Create and init a empty alphabet*/
t_alphabet* alphabet_create();

/*Destroy and free a alphabet*/
void alphabet_destroy(t_alphabet* alphabet);

/*Set alphabet->elements = elements*/
void alphabet_set_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);

/*Add elements to the existing into the alphabet*/
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);

char* element_get_upCase();

char* element_get_lowCase();

char* element_get_numbers();


#endif
