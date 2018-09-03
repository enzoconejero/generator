
#include "language.h"

//Tested
t_language* language_create(){
	t_language* language = (t_language*) malloc(sizeof(t_language));
	language->alphabet = alphabet_create();
	language->equals = NULL;
	language->first = NULL;
	language->last = NULL;
	return language;
}

void language_destroy(t_language* language){
	alphabet_destroy(language->alphabet);
	free(language);
	//TODO
}

//Tested
void language_set_alphabet(t_language* language, t_alphabet* alphabet){
	alphabet_destroy(language->alphabet);
	language->alphabet = alphabet;
}

//Tested
void language_set_equal(t_language* language, bool(*equal)(void*,void*)){
	language->equals = equal;
}

//TODO TEST
void language_set_first_from_string(t_language* language, const char* string){
	free(language->first);
	size_t lenght = strlen(string);
	language->first = malloc(lenght + 1);
	memset(language->first, 0, lenght);
	memcpy(language->first, string, lenght);
	((char*)language->first)[lenght] = '\0';
}

//TODO TEST
void language_set_last_from_string(t_language* language, const char* string){
	free(language->last);
	size_t lenght = strlen(string);
	language->last = malloc(lenght + 1);
	memset(language->last, 0, lenght);
	memcpy(language->last, string, lenght);
	memcpy(language->last, string, lenght);
	((char*)language->last)[lenght] = '\0';
}

//TODO TEST
bool equals_elements_char(char c1, char c2){
	return c1 == c2;
}

//TODO TEST
bool equals_words_char(const char* c1,const char* c2){
	return strcmp(c1, c2) == 0;
}
