
#include "main.h"

bool stop(t_gcb* gcb);
bool stop_sudoku(t_gcb* gcb);
void print_string(t_gcb* gcb);

int main(int argc, char** argv){
	total = 0;
	mill = 0;
	
	t_language* language = language_create();
	/*
	language_set_equal(language, &equals_char);
	language_set_filter(language, &filter_name);
	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, 1);
	language_set_print(language, &print_string);

	t_generator* generator = generator_create(language);

	generator_set_stop_condition(generator, &stop);

	generator_set_initial_word(generator, "liz", 3);
	// generator_set_initial_length(generator, 3);
	generate( generator );
	*/

	language_set_equal(language, &equals_int8);
	language_set_print(language, &print_sudoku);
	// printf("0\n");
	language_set_filter(language, &filter_sudoku);
	// printf("1\n");
	language_set_element(language, element_get_num(1, 9, I8), 9, 1);
	// printf("2\n");
	t_generator* generator = generator_create(language);
	// printf("3\n");
	generator_set_initial_length(generator, 81);
	// printf("4\n");
	generator_set_stop_condition(generator, &stop_sudoku);
	// printf("5\n");
	generate(generator);

	return 0;
}

bool stop(t_gcb* gcb){
	return gcb->current_length < 20;
}

bool stop_sudoku(t_gcb* gcb){
	return gcb->current_length != 81;
}