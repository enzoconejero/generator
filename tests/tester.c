
#include "alphabets-test.h"

void testBasico();

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
