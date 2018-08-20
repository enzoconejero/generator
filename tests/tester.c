
#include <stdio.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>


void testBasico();

int main(int argc, char** argv){
	CU_initialize_registry();
	CU_pSuite prueba = CU_add_suite("Suite de prueba", NULL, NULL);
	CU_add_test(prueba, "Basico", testBasico);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}

void testBasico(){
	CU_ASSERT_EQUAL(1,1);
}
