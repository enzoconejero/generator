
#include "elements-test.h"

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