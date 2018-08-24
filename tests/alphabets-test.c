
#include <stdio.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "alphabets-test.h"

void testAlphabetsLow(){
	char* alphabet = get_letters(LOW);
	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL(alphabet[i], 'a'+i);
	}
}

void testAlphabetsCapital(){
	char* alphabet = get_letters(CAPITAL);
	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL(alphabet[i], 'A'+i);
	}
}

void testAlphabetsNumber(){
	char* alphabet = get_letters(NUMBERS);
	for(int i = 0; i < 10; i++){
		CU_ASSERT_EQUAL(alphabet[i], '0'+i);
	}
}

void testAlphabetsAlphaNumeric(){
	char* alphabet = get_letters(ALL);
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
