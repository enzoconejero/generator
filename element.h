
#ifndef ELEMENT_H
#define ELEMENT_H

#include "commons-includes.h"

typedef enum{
	UI8,
	UI16,
	UI32,
	UI64,
	I8,
	I16,
	I32,
	I64
}t_int;

/*Get chars A-Z*/
char* element_get_upCase();

/*Get chars a-z*/
char* element_get_lowCase();

/*Get chars 0-9*/
char* element_get_numbers();

void* element_get_num(int64_t initial, int64_t final, t_int size);

#endif
