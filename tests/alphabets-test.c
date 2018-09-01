
#include "alphabets-test.h"

void testAlphabetCreator(){
	t_alphabet* alphabet = alphabet_create();
	CU_ASSERT( alphabet != NULL );
	CU_ASSERT( alphabet->elements == NULL );
	CU_ASSERT( alphabet->elements_count == 0 );
	CU_ASSERT( alphabet->elements_size == 0 );
	CU_ASSERT( alphabet->last_element == '\0');
}

void testSetElemts(){
	t_alphabet* alphabet = alphabet_create();
	int* elements1 = malloc(sizeof(int) * 5);
	for(int i = 0; i < 5; i++){
		elements1[i] = i;
	}
	alphabet_set_element(alphabet, elements1, 5, sizeof(int));

	for(int i = 0; i < 5; i++){
		CU_ASSERT_EQUAL( ((int*) (alphabet->elements))[i], i);
	}
}

void testAddElemtsInEmptyAlphabet(){
	t_alphabet* alphabet = alphabet_create();
	//Elements array create
	int* elements1 = malloc(sizeof(int) * 5);
	for(int i = 0; i < 5; i++){
		elements1[i] = i;
	}
	alphabet_add_element(alphabet, elements1, 5, sizeof(int));

	for(int i = 0; i < 5; i++){
		CU_ASSERT_EQUAL( ((int*) (alphabet->elements))[i], i);
	}
}

void testAddElemtsInNotEmptyAlphabet(){
	t_alphabet* alphabet = alphabet_create();
	//Elements array create
	int* elements_set = malloc(sizeof(int) * 5);
	for(int i = 0; i < 5; i++){
		elements_set[i] = i;
	}
	alphabet_set_element(alphabet, elements_set, 5, sizeof(int));

	for(int i = 0; i < 5; i++){
		CU_ASSERT_EQUAL( ((int*) (alphabet->elements))[i], i);
	}

	//New elements array create
	int* elements_add = malloc(sizeof(int) * 5);
	for(int i = 0; i < 5; i++){
		elements_add[i] = i+5;
	}
	alphabet_add_element(alphabet, elements_add, 5, sizeof(int));

	for(int i = 0; i < 5; i++){
		CU_ASSERT_EQUAL( ((int*) (alphabet->elements))[i+5], i+5);
	}
}

//void testAlphabetsLow(){
//	char* alphabet = get_letters(LOW);
//	for(int i = 0; i < LETTERS_COUNT; i++){
//		CU_ASSERT_EQUAL(alphabet[i], 'a'+i);
//	}
//
//	t_alphabet* alfa = alphabet_create();
//	alphabet_add_elements(alfa, alphabet, LETTERS_COUNT);
//	t_language* language = language_create();
//	language_set_alphabet(language, alfa);
//	CU_ASSERT_EQUAL(alfa->elements_count, LETTERS_COUNT);
//	for(int i = 0; i < language->alphabet->elements_count; i++){
//		CU_ASSERT_EQUAL(language->alphabet->elements[i], 'a'+i);
//	}
//}
//
//void testAlphabetsCapital(){
//	char* alphabet = get_letters(CAPITAL);
//	for(int i = 0; i < LETTERS_COUNT; i++){
//		CU_ASSERT_EQUAL(alphabet[i], 'A'+i);
//	}
//
//	t_alphabet* alfa = alphabet_create();
//	alphabet_add_elements(alfa, alphabet, LETTERS_COUNT);
//	t_language* language = language_create();
//	language_set_alphabet(language, alfa);
//	CU_ASSERT_EQUAL(alfa->elements_count, LETTERS_COUNT);
//	for(int i = 0; i < language->alphabet->elements_count; i++){
//		CU_ASSERT_EQUAL(language->alphabet->elements[i], 'a'+i);
//	}
//}
//
//void testAlphabetsNumber(){
//	char* alphabet = get_letters(NUMBERS);
//	for(int i = 0; i < 10; i++){
//		CU_ASSERT_EQUAL(alphabet[i], '0'+i);
//	}
//
//	t_alphabet* alfa = alphabet_create();
//	alphabet_add_elements(alfa, alphabet, 10);
//	t_language* language = language_create();
//	language_set_alphabet(language, alfa);
//	CU_ASSERT_EQUAL(alfa->elements_count, 10);
//	for(int i = 0; i < language->alphabet->elements_count; i++){
//		CU_ASSERT_EQUAL(language->alphabet->elements[i], 'a'+i);
//	}
//}
//
//void testAlphabetsAlphaNumeric(){
//	char* alphabet = get_letters(ALL);
//	for(int i = 0; i < LETTERS_COUNT; i++){
//		CU_ASSERT_EQUAL(alphabet[i], 'a'+i);
//	}
//
//	for(int i = 0; i < LETTERS_COUNT; i++){
//		CU_ASSERT_EQUAL(alphabet[LETTERS_COUNT+i], 'A'+i);
//	}
//
//	for(int i = 0; i < 10; i++){
//		CU_ASSERT_EQUAL(alphabet[LETTERS_COUNT*2+i], '0'+i);
//	}
//
//	t_alphabet* alfa = alphabet_create();
//	alphabet_add_elements(alfa, alphabet, 256);
//	t_language* language = language_create();
//	language_set_alphabet(language, alfa);
//	CU_ASSERT_EQUAL(alfa->elements_count, 256);
//
//	for(int i = 0; i < LETTERS_COUNT; i++){
//		CU_ASSERT_EQUAL(language->alphabet->elements[i], 'a'+i);
//	}
//
//	for(int i = 0; i < LETTERS_COUNT; i++){
//		CU_ASSERT_EQUAL(language->alphabet->elements[LETTERS_COUNT+i], 'A'+i);
//	}
//
//	for(int i = 0; i < 10; i++){
//		CU_ASSERT_EQUAL(language->alphabet->elements[LETTERS_COUNT*2+i], '0'+i);
//	}
//}
