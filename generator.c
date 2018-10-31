
#include "generator.h"

int main(int argc, char** argv){

	t_language* language = language_create();
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet, &equals_int8);	

	// alphabet_set_element(alphabet, element_get_num(0, 9, UI8), 10, sizeof(int8_t));

	int8_t* elements = malloc(10);

	for (int i = 0; i < 10; ++i){
		elements[i] = i;
	}

	alphabet_set_element(alphabet, elements, 10, sizeof(int8_t));

	language_set_alphabet(language, alphabet);
	generate(language);

	return 0;
}
