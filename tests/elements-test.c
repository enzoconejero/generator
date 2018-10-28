
#include "elements-test.h"

void testGetLowCasesElements(){
	char* lowCases = element_get_lowCase();
	for(char i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL(lowCases[i] , 'a' + i);
	}
}

void testGetUpCasesElements(){
	char* upCases = element_get_upCase();
	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL(upCases[i] , 'A' + i);
	}
}

void testGetNumbersElements(){
	char* numbers = element_get_numbers();
	for(int i = 0; i < 10; i++){
		CU_ASSERT_EQUAL(numbers[i] , '0' + i);
	}
}

void testGetNumFailWhenFinalLessThanInitial(){
	void* elements = element_get_num(10, 0, UI8);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(10, 0, UI16);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(10, 0, UI32);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(10, 0, UI64);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(10, 0, I8);
	CU_ASSERT_PTR_NULL(elements);	

	elements = element_get_num(10, 0, I16);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(10, 0, I32);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(10, 0, I64);
	CU_ASSERT_PTR_NULL(elements);
}

void testGetNumFailWhenCountGreaterThanMax(){
	void* elements = element_get_num(0, pow(2,8), UI8);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(0, pow(2,16), UI16);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(0, pow(2,32), UI32);
	CU_ASSERT_PTR_NULL(elements);

	// elements = element_get_num(0, pow(2,64) + 1, UI64);
	// CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(0, pow(2,8), I8);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(0, pow(2,16), I16);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(0, pow(2,32), I32);
	CU_ASSERT_PTR_NULL(elements);

	// elements = element_get_num(0, 9223372036854775807, I64);
	// CU_ASSERT_PTR_NULL(elements);
}
 
void testGetNumFailWhenInitialIsNegativeAtUnsignedType(){
	void* elements = element_get_num(-1, 1, UI8);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(-1, 1, UI16);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(-1, 1, UI32);
	CU_ASSERT_PTR_NULL(elements);

	elements = element_get_num(-1, 1, UI64);
	CU_ASSERT_PTR_NULL(elements);
}

void testGetNumFrom0to100(){
	void* elements = element_get_num(0, 100, UI8);

	CU_ASSERT_PTR_NOT_NULL(elements);
	for (int i = 0; i < 101; ++i){
		CU_ASSERT_EQUAL(*(u_int8_t*)elements + i, i);
	}
}
