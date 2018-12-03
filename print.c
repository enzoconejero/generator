
#include "print.h"

void print_string(t_gcb* gcb){
	char* name = malloc(gcb->current_length + 1);
	memcpy(name, gcb->word, gcb->current_length);
	name[gcb->current_length] = '\0';
	printf("%s\t", name);
	getchar();
	free(name);
}