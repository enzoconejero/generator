
#include "languagues-test.h"

void testLanguagesCreator(){
	t_language* language = language_create();
	CU_ASSERT_EQUAL(language->alphabet->elements, NULL);
	CU_ASSERT_EQUAL(language->alphabet->last_element, NULL);
	CU_ASSERT_EQUAL(language->alphabet->elements_size, 0);
	CU_ASSERT_EQUAL(language->alphabet->elements_count, 0);
	language_destroy(language);
}
