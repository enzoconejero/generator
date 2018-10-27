
#include "languages-test.h"

void testLanguageCreate(){
	t_language* language = language_create();
	CU_ASSERT_EQUAL(language->alphabet, NULL)
	language_destroy(language);
}

void testSetAlphabet(){
	t_language* language = language_create();
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet, &equals_char);
	alphabet_set_element(alphabet, element_get_lowCase(), LETTERS_COUNT, sizeof(char));
	language_set_alphabet(language, alphabet);
	CU_ASSERT( language->alphabet->elements_size == 1 );
	CU_ASSERT( *(char*)language->alphabet->last_element == 'z' );
	language_destroy(language);
}
