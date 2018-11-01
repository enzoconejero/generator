
#include "generator.h"

int main(int argc, char** argv){
	
	t_language* language = language_create();
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet, &equals_int8);	
	alphabet_set_element(alphabet, element_get_num(0, 9, UI8), 10, sizeof(int8_t));
	language_set_alphabet(language, alphabet);
	language_set_print(language, &print_int8);
	generate(language);

	return 0;
}
