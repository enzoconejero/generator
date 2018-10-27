
#include "alphabets-test.h"
#include "languages-test.h"
void testBasico();

int main(int argc, char** argv){
	CU_initialize_registry();
	CU_pSuite prueba = CU_add_suite("Test suite", NULL, NULL);
	CU_add_test(prueba, "Basic", testBasico);

	CU_pSuite alphabets = CU_add_suite("Alphabets tests", NULL, NULL);
	CU_add_test(alphabets, "Get lowCase elements", testGetLowCasesElements);
	CU_add_test(alphabets, "Get upCase elements", testGetUpCasesElements);
	CU_add_test(alphabets, "Get numbers elements", testGetNumbersElements);
	CU_add_test(alphabets, "Char equals", testCharEqual);
	CU_add_test(alphabets, "Int8 equals", testInt8Equal);
	CU_add_test(alphabets, "Set equals", testSetEquals);
	CU_add_test(alphabets, "Constructor", testAlphabetCreate);
	CU_add_test(alphabets, "Set elements in empty alphabet", testSetElementsInEmptyAlphabet);
	CU_add_test(alphabets, "Set elements in no empty alphabet", testSetElementsInNoEmptyAlphabet);
	CU_add_test(alphabets, "Set repeated elements in empty alphabet", testSetRepeatedElementsInNoEmptyAlphabet);
	CU_add_test(alphabets, "Add elements in empty alphabet", testAddElementsInEmptyAlphabet);
	CU_add_test(alphabets, "Add elements in not empty alphabet", testAddElementsInNotEmptyAlphabet);
	CU_add_test(alphabets, "Add repeated elements in not empty alphabet", testAddRepeatedElementsInNotEmptyAlphabet);

	CU_pSuite languages = CU_add_suite("Languages tests", NULL, NULL);
	CU_add_test(languages, "Constructor", testLanguageCreate);
	CU_add_test(languages, "Set alphabet", testSetAlphabet);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}

void testBasico(){
	CU_ASSERT_EQUAL(1,1);
}
