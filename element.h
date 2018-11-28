
#ifndef ELEMENT_H
#define ELEMENT_H

#include "commons-includes.h"
#include "logger.h"

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

/*Get numbers on the designed interval*/
void* element_get_num(double initial, double final, t_int size);

#endif
