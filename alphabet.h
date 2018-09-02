
#ifndef ALPHABET_H
#define ALPHABET_H

#include "commons-includes.h"

typedef struct{
	size_t elements_count;
	size_t elements_size; //Must be unalterable
	void* elements;
	void* last_element; //Must redefine to void*
}t_alphabet;


/*Create and init a empty alphabet*/
t_alphabet* alphabet_create();

/*Destroy and free a alphabet*/
void alphabet_destroy(t_alphabet* alphabet);

/*Set alphabet->elements = elements*/
void alphabet_set_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);

/*Add elements to the existing into the alphabet*/
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);

/*Get chars A-Z*/
char* element_get_upCase();

/*Get chars a-z*/
char* element_get_lowCase();

/*Get chars 0-9*/
char* element_get_numbers();


#endif

