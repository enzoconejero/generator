
#include "language.h"

//Tested
t_language* language_create(){
	t_language* language = (t_language*) malloc(sizeof(t_language));
	language->alphabet = NULL;
	return language;
}

//Tested
void languaje_destroy(t_language* languaje){
	free(languaje->alphabet);
	free(languaje);
}

//Tested
void languaje_set_alphabet(t_language* languaje, t_alphabet* alphabet){
	if(languaje->alphabet == NULL){
		free(languaje->alphabet);
	}
	languaje->alphabet = alphabet;
}



