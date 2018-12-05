
#include "main.h"

bool stop(t_gcb* gcb);
bool stop_sudoku(t_gcb* gcb);
void print_string(t_gcb* gcb);
void show_status();

int main(int argc, char** argv){
	/*
	total = 0;
	mill = 0;
	*/
	
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
	language_set_filter(language, &filter_sudoku);
	language_set_element(language, element_get_num(1, 9, I8), 9, 1);
	t_generator* generator = generator_create(language);

	int8_t initial[81] = 
	{1,2,3,4,5,6,7,8,9
	,4,5,6,7,8,9,1,2,3
	,7,8,9,1,2,3,4,5,6
	,2,3,1,6,4,5,8,9,7
	,6,4,5,8,9,7,2,3,1
	,8,9,7,2,3,1,6,4,5
	,3,1,2,5,6,4,9,7,8
	,5,6,4,9,7,8,3,1,2
	,9,7,8,3,1,2,5,6,4};
	generator_set_initial_word(generator, initial, 81);
	generator_set_stop_condition(generator, &stop_sudoku);
	
	pthread_t show;
	pthread_create(&show, NULL, (void*)&show_status, NULL);
	generate(generator);
	

	return 0;
}

bool stop(t_gcb* gcb){
	return gcb->current_length < 20;
}

bool stop_sudoku(t_gcb* gcb){
	return gcb->current_length != 81;
}

void show_status(){
	unsigned long aux;
	unsigned long minutos = 0;

	while(1){

		sleep(60);
		
		aux = total;
		total %= 1000000; 
		minutos++;

		printf("Minuto %lu, Millones %lu\n", minutos, aux/1000000);
	}
}