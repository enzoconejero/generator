
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


/*Create and init a empty alphabet*/
t_alphabet* alphabet_create();

/*Destroy and free a alphabet*/
void alphabet_destroy(t_alphabet* alphabet);

/*Set alphabet->elements = elements*/
void alphabet_set_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);

/*Add elements to the existing into the alphabet*/
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size);

/*Set function wich return if 2 elements are equals*/
void alphabet_set_equal(t_alphabet* alphabet, bool(*equal)(void*,void*));

void set_equals_byte_to_byte(t_alphabet* alphabet, size_t element_size);

bool equals_char(void* c1, void* c2);

///*Predefined equals*/
bool equals_elements_char(char c1, char c2);
bool equals_words_char(const char* c1,const char* c2);

/*Get chars A-Z*/
char* element_get_upCase();

/*Get chars a-z*/
char* element_get_lowCase();

/*Get chars 0-9*/
char* element_get_numbers();


#endif

