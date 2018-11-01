
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "alphabet.h"
#include "element.h"

typedef struct{
	t_alphabet* alphabet;
	void (*print)(void*);
}t_language;

/*Create a languaje*/
t_language* language_create();
void language_destroy(t_language* language);
void language_set_alphabet(t_language* language, t_alphabet* alphabet);
void language_set_print(t_language* language, void (*print)(void* a));


void generate();

#endif /* LANGUAGE_H_ */
