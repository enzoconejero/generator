#include "generator.h"

int main(int argc, char** argv){

	t_language* language = language_create();
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet, &equals_int8);

	void* elements = malloc(sizeof(int8_t) * 10);
	for (int i = 0;i < 10;
		memcpy(elements + i * sizeof(int8_t), &i, sizeof(int8_t)),
		++i);

	alphabet_set_element(alphabet, elements, 10, sizeof(int8_t));
	language_set_alphabet(language, alphabet);
	generate(language);

	return 0;
}