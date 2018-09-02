
#include "alphabets-test.h"
#include "languagues-test.h"
void testBasico();

int main(int argc, char** argv){
	CU_initialize_registry();
	CU_pSuite prueba = CU_add_suite("Suite de prueba", NULL, NULL);
	CU_add_test(prueba, "Basico", testBasico);

	CU_pSuite alphabets = CU_add_suite("Alphabets tests", NULL, NULL);
	CU_add_test(alphabets, "Constructor", testAlphabetCreator);
	CU_add_test(alphabets, "Set elements", testSetElemts);
	CU_add_test(alphabets, "Add elements in empty alphabet", testAddElemtsInEmptyAlphabet);
	CU_add_test(alphabets, "Add elements in not empty alphabet", testAddElemtsInNotEmptyAlphabet);
	CU_add_test(alphabets, "Get lowCase elements", testGetLowCasesElements);
	CU_add_test(alphabets, "Get upCase elements", testGetUpCasesElements);
	CU_add_test(alphabets, "Get numbers elements", testGetNumbersElements);

	CU_pSuite languages = CU_add_suite("Languages tests", NULL, NULL);
	CU_add_test(languages, "Constructor", testLanguagesCreator);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}

void testBasico(){
	CU_ASSERT_EQUAL(1,1);
}
