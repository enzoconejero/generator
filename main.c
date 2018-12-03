
#include "main.h"

bool stop(t_gcb* gcb);
void print_string(t_gcb* gcb);

int main(int argc, char** argv){

	t_language* language = language_create();
	// language_set_equal(language, &equals_int8);	
	// language_set_element(language, element_get_num(0, 9, UI8), 10, sizeof(int8_t));
	// language_set_print(language, &print_int8);
	// language_set_equal(language, &equals_char);
	// language_set_print(language, &print_char);
	// language_set_filter(language, &filter_name);
	// language_set_element(language, element_get_lowCase(), LETTERS_COUNT, 1);
	// language_add_element(language, element_get_upCase(), LETTERS_COUNT, 1);
	// language_add_element(language, element_get_numbers(), 10, 1);
	// language_add_element(language, element_get_c_special(), 23, 1);
	// generate_dmmy(language);
	// generate_length(language, 5);

	language_set_equal(language, &equals_char);
	language_set_filter(language, &filter_name);
	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, 1);
	language_set_print(language, &print_string);

	t_generator* generator = generator_create(language);

	generator_set_stop_condition(generator, &stop);
	
	
	generate( generator );

	// generate(  );

	return 0;
}

bool stop(t_gcb* gcb){
	return gcb->current_length < 5;
}

void print_string(t_gcb* gcb){
	char* name = malloc(gcb->current_length + 1);
	memcpy(name, gcb->word, gcb->current_length);
	name[gcb->current_length] = '\0';
	printf("%s\t", name);
	free(name);
}