
#include "languages-test.h"
#include "elements-test.h"

int main(int argc, char** argv){
	CU_initialize_registry();

	CU_pSuite elements = CU_add_suite("Elements tests", NULL, NULL);
	CU_add_test(elements, "Get lowCase elements", testGetLowCasesElements);
	CU_add_test(elements, "Get upCase elements", testGetUpCasesElements);
	CU_add_test(elements, "Get numbers elements", testGetNumbersElements);
	CU_add_test(elements, "Get num fails when Final < Intitial", testGetNumFailWhenFinalLessThanInitial);
	CU_add_test(elements, "Get num fails when initial < 0 in a unsigned type", testGetNumFailWhenInitialIsNegativeAtUnsignedType);
	CU_add_test(elements, "Get num fails when count > max", testGetNumFailWhenCountGreaterThanMax);
	CU_add_test(elements, "Get num 0 to 100", testGetNumFrom0to100);
	CU_add_test(elements, "Get num for all the types", testGetNumForAlTheTypes);

	CU_pSuite languages = CU_add_suite("Languages tests", NULL, NULL);
	CU_add_test(languages, "Char equals", testCharEqual);
	CU_add_test(languages, "Int8 equals", testInt8Equal);
	CU_add_test(languages, "Set equals", testSetEquals);
	CU_add_test(languages, "Constructor", testLanguageCreate);
	CU_add_test(languages, "Set elements in empty language", testSetElementsInEmptyLanguage);
	CU_add_test(languages, "Set elements in no empty language", testSetElementsInNoEmptyLanguage);
	CU_add_test(languages, "Set repeated elements in empty language", testSetRepeatedElementsInNoEmptyLanguage);
	CU_add_test(languages, "Add elements in empty language", testAddElementsInEmptyLanguage);
	CU_add_test(languages, "Add elements in not empty language", testAddElementsInNotEmptyLanguage);
	CU_add_test(languages, "Add repeated elements in not empty language", testAddRepeatedElementsInNotEmptyLanguage);
	CU_add_test(languages, "Get element at index", testGetElementAtIndex);
	CU_add_test(languages, "Constructor", testLanguageCreate);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}
