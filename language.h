
#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include "commons-includes.h"
#include "alphabet.h"

typedef struct{
	t_alphabet* alphabet;
//	bool (*equals)(void*, void*);
	void* first;
	void* last;
}t_language;

typedef struct{
	t_language language;
//	char* path;
//	FILE* persistence_file;
}t_instance_generator;

/*Create a language structure*/
t_language* language_create();

/*Free memory*/
void language_destroy(t_language* language);

/*Set an alphabet for a language*/
void language_set_alphabet(t_language* language, t_alphabet* alphabet);

//void language_set_equal(t_language* language, bool(*equal)(void*,void*));

/*Set the initial word*/
void language_set_first_from_string(t_language* language, const char* string);
void language_set_last_from_string(t_language* language, const char* string);
//bool equals_elements_char(char c1, char c2);
//bool equals_words_char(const char* c1,const char* c2);



void generate_words(char* last_word);

#endif /* LANGUAGE_H_ */
