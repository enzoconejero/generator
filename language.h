
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "alphabet.h"

typedef struct{
	t_alphabet* alphabet;
}t_language;

typedef struct{
	t_language language;
	char* path;
	FILE* persistence_file;
}t_instance_generator;

t_language* language_create();
void language_set_alphabet(t_language* language, t_alphabet* alphabet);
void generate_words(char* last_word);

#endif /* LANGUAGE_H_ */
