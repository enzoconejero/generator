
#include "languagues-test.h"

void testLanguagesCreator(){
	t_language* language = language_create();
	CU_ASSERT_EQUAL(language->alphabet->elements, NULL);
	CU_ASSERT_EQUAL(language->alphabet->last_element, NULL);
	CU_ASSERT_EQUAL(language->alphabet->elements_size, 0);
	CU_ASSERT_EQUAL(language->alphabet->elements_count, 0);
	CU_ASSERT_EQUAL(language->equals, NULL);
	language_destroy(language);
}

void testSetAlphabet(){
	t_language* language = language_create();
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_element(alphabet, element_get_lowCase(), LETTERS_COUNT, sizeof(char));
	language_set_alphabet(language, alphabet);

	CU_ASSERT_EQUAL( *((char*)(language->alphabet->last_element)), 'z');
	CU_ASSERT_EQUAL(language->alphabet->elements_size, sizeof(char));
	CU_ASSERT_EQUAL(language->alphabet->elements_count, LETTERS_COUNT);
	CU_ASSERT_EQUAL(language->alphabet, alphabet);

	language_destroy(language);
}

void testEqualElement(){
	t_language* language = language_create();
	alphabet_set_element(language->alphabet, element_get_lowCase(), LETTERS_COUNT, sizeof(char));

	bool equals(void* element1, void* element2){
		char c1 = *(char*)element1;
		char c2 = *(char*)element2;
		return c1 == c2;
	}

	char c1 = 'a';
	char c2 = 'a';

	language->equals = &equals;

	CU_ASSERT( (*language->equals)(&c1, &c2 ));
	CU_ASSERT( (*language->equals)( language->alphabet->last_element, "z") );
}

void testSetEqual(){
	t_language* language = language_create();
	bool equals(void* element1, void* element2){
		char c1 = *(char*)element1;
		char c2 = *(char*)element2;
		return true;
	}

	char c1 = 'a';
	char c2 = 'a';

	language_set_equal(language, equals);

	CU_ASSERT( (*language->equals)(&c1, &c2 ));
	CU_ASSERT( (*language->equals)( language->alphabet->last_element, "z") );

}
