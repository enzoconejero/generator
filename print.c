
#include "print.h"

void print_string(t_gcb* gcb){
	char* name = malloc(gcb->current_length + 1);
	memcpy(name, gcb->word, gcb->current_length);
	name[gcb->current_length] = '\0';
	printf("%s\t", name);
	getchar();
	free(name);
}

void print_sudoku(t_gcb* gcb){
	NL;
	printf("Sudoku:\n");
	for(int i = 0; i < 81; i++){
		printf("%d\t", *(int8_t*)(gcb->word + i) );
		if( ((i+1) % 9) == 0 ){
					NL;
		}
	}
	getchar();
}