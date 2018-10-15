
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "alphabet.h"

typedef struct{
	t_alphabet* alphabet;
}t_language;

t_language* language_create();
void languaje_destroy(t_language* languaje);
void languaje_set_alphabet(t_language* languaje, t_alphabet* alphabet);

#endif /* LANGUAGE_H_ */
