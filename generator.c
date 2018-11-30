
#include "generator.h"

int main(int argc, char** argv){

	t_language* language = language_create();
	// language_set_equal(language, &equals_int8);	
	// language_set_element(language, element_get_num(0, 9, UI8), 10, sizeof(int8_t));
	// language_set_print(language, &print_int8);
	language_set_equal(language, &equals_char);
	language_set_print(language, &print_char);
	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, 1);
	language_add_element(language, element_get_upCase(), LETTERS_COUNT, 1);
	language_add_element(language, element_get_numbers(), 10, 1);
	language_add_element(language, element_get_c_special(), 23, 1);
	// generate_dmmy(language);
	generate_lenght(language, 5);

	return 0;
}
