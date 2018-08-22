
#include <stdio.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "../alphabet.h"

void testBasico();
void testAlphabetsLow();
void testAlphabetsCapital();
void testAlphabetsNumber();
void testAlphabetsAlphaNumeric();

int main(int argc, char** argv){
	CU_initialize_registry();
	CU_pSuite prueba = CU_add_suite("Suite de prueba", NULL, NULL);
	CU_add_test(prueba, "Basico", testBasico);

	CU_pSuite alphabets = CU_add_suite("Alphabets tests", NULL, NULL);
	CU_add_test(alphabets, "Low Case", testAlphabetsLow);
	CU_add_test(alphabets, "Up Case", testAlphabetsCapital);
	CU_add_test(alphabets, "Numbers", testAlphabetsNumber);
	CU_add_test(alphabets, "All alphanumeric", testAlphabetsAlphaNumeric);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}

void testBasico(){
	CU_ASSERT_EQUAL(1,1);
}

void testAlphabetsLow(){
	t_element* alphabet = get_letters(LOW);
	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL(alphabet[i], 'a'+i);
	}
}

void testAlphabetsCapital(){
	t_element* alphabet = get_letters(CAPITAL);
	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL(alphabet[i], 'A'+i);
	}
}

void testAlphabetsNumber(){
	t_element* alphabet = get_letters(NUMBERS);
	for(int i = 0; i < 10; i++){
		CU_ASSERT_EQUAL(alphabet[i], '0'+i);
	}
}

void testAlphabetsAlphaNumeric(){
	t_element* alphabet = get_letters(ALL);
	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL(alphabet[i], 'a'+i);
	}

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL(alphabet[LETTERS_COUNT+i], 'A'+i);
	}

	for(int i = 0; i < 10; i++){
		CU_ASSERT_EQUAL(alphabet[LETTERS_COUNT*2+i], '0'+i);
	}
}
