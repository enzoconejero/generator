
#include "languagues-test.h"

void testLanguageCreate(){
	t_language* language = language_create();
	CU_ASSERT_EQUAL(language->alphabet, NULL)
	languaje_destroy(language);
}

void testSetAlphabet(){
	t_language* language = language_create();
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet, &equals_char);
	languaje_set_alphabet(language, alphabet);
	CU_ASSERT( language->alphabet->elements_size == 1 );
	CU_ASSERT( *(char*)language->alphabet->last_element == 'z' );
	languaje_destroy(language);
}
