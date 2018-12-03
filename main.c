
#include "main.h"

bool stop(t_gcb* gcb);
void print_string(t_gcb* gcb);

int main(int argc, char** argv){

	t_language* language = language_create();

	language_set_equal(language, &equals_char);
	language_set_filter(language, &filter_name);
	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, 1);
	language_set_print(language, &print_string);

	t_generator* generator = generator_create(language);

	generator_set_stop_condition(generator, &stop);

	// generator_set_initial_word(generator, "liz", 3);
	generator_set_initial_length(generator, 3);
	generate( generator );

	return 0;
}

bool stop(t_gcb* gcb){
	return gcb->current_length < 20;
}