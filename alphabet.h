
#ifndef ALPHABET_H
#define ALPHABET_H

#include "commons-includes.h"

typedef struct{
	size_t elements_count;
	size_t elements_size;
	void* elements;
	void* last_element;
	bool (*equals)(void*, void*);
}t_alphabet;


/*Create and init an empty alphabet*/
t_alphabet* alphabet_create();

/*Destroy and free an alphabet*/
void alphabet_destroy(t_alphabet* alphabet);

/*Set alphabet->elements = elements*/
void alphabet_set_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);

/*Add elements to the existing into the alphabet*/
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);

/*Set function which returns if 2 elements are equals*/
void alphabet_set_equal(t_alphabet* alphabet, bool(*equal)(void*,void*));

bool equals_char(void* c1, void* c2);
bool equals_int8(void* c1, void* c2);

#endif

