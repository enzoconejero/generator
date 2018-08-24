
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "alphabet.h"

typedef struct{
	t_alphabet* alphabet;
}t_language;

void generate_words(char* last_word);

#endif /* LANGUAGE_H_ */
