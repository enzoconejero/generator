
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "alphabet.h"

typedef struct{
	t_alphabet* alphabet;
	bool (*equals)(void*, void*);
}t_language;

typedef struct{
	t_language language;
//	char* path;
//	FILE* persistence_file;
}t_instance_generator;

t_language* language_create();
void language_destroy(t_language* language);
void language_set_alphabet(t_language* language, t_alphabet* alphabet);
void language_set_equal(t_language* language, bool(*equal)(void*,void*));

void generate_words(char* last_word);

#endif /* LANGUAGE_H_ */
