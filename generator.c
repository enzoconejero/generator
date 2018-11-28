
#include "generator.h"

int main(int argc, char** argv){

	t_language* language = language_create();
	language_set_equal(language, &equals_int8);	
	language_set_element(language, element_get_num(0, 9, UI8), 10, sizeof(int8_t));
	language_set_print(language, &print_int8);
	generate(language);

	return 0;
}
