
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "alphabet.h"

typedef struct{
	t_alphabet* alphabet;
}t_language;

/*Create a languaje*/
t_language* language_create();
void language_destroy(t_language* languaje);
void language_set_alphabet(t_language* languaje, t_alphabet* alphabet);
void generate();

#endif /* LANGUAGE_H_ */
