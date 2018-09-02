
#include "language.h"

t_language* language_create(){
	t_language* language = (t_language*) malloc(sizeof(t_language));
	language->alphabet = alphabet_create();
	return language;
}

void language_destroy(t_language* language){
	alphabet_destroy(language->alphabet);
	free(language);
	//TODO
}

void language_set_alphabet(t_language* language, t_alphabet* alphabet){
	alphabet_destroy(alphabet);
	language->alphabet = alphabet;
}

