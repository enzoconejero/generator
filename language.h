
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "element.h"
#include "equal.h"
#include "filter.h"

/*Create a languaje*/
t_language* language_create();

void language_destroy(t_language* language);
// void language_set_language(t_language* language, t_language* language);
void language_set_print(t_language* language, void (*print) (t_gcb*));

void language_set_filter(t_language* language,bool (*filter)(t_gcb*));

void language_set_element(t_language* language, void* elements, size_t elements_count, size_t elements_size);

/*Add elements to the existing into the language*/
void language_add_element(t_language* language, void* elements, size_t elements_count, size_t elements_size);

/*Set function which returns if 2 elements are equals*/
void language_set_equal(t_language* language, bool(*equal)(void*,void*));

void* language_get_element_at(t_language* language, int index);

int language_indexOf(t_language* language, void* element);

bool language_is_valid_word(t_language* language, void* word, size_t length);

#endif /* LANGUAGE_H_ */
