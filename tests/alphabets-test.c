
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

void testGetLowCasesElements(){
	char* lowCases = element_get_lowCase();
	for(char i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( lowCases[i] , 'a' + i );
	}
}

void testGetUpCasesElements(){
	char* upCases = element_get_upCase();
	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( upCases[i] , 'A' + i );
	}
}

void testGetNumbersElements(){
	char* numbers = element_get_numbers();
	for(int i = 0; i < 10; i++){
		CU_ASSERT_EQUAL( numbers[i] , '0' + i);
	}
}
