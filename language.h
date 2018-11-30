
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "element.h"
#include "equal.h"

typedef struct{
	size_t elements_count;
	size_t elements_size;
	void* elements;
	void* last_element;
	bool (*equals)(void*, void*);
	void (*print)(void*);
}t_language;

/*Create a languaje*/
t_language* language_create();
void language_destroy(t_language* language);
// void language_set_language(t_language* language, t_language* language);
void language_set_print(t_language* language, void (*print)(void* a));

void language_set_element(t_language* language, void* elements, size_t elements_count, size_t elements_size);

/*Add elements to the existing into the language*/
void language_add_element(t_language* language, void* elements, size_t elements_count, size_t elements_size);

/*Set function which returns if 2 elements are equals*/
void language_set_equal(t_language* language, bool(*equal)(void*,void*));

void* language_get_element_at(t_language* language, int index);

void generate_dmmy(t_language* language);

void generate_lenght(t_language* language, int length);

#endif /* LANGUAGE_H_ */
