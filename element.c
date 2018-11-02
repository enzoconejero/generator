
#include "element.h"

//Tested
char* element_get_upCase(){
	char* elements = malloc(LETTERS_COUNT);
	for(int i = 0; i < LETTERS_COUNT; elements[i] = 'A' + i, i++);
	return elements;
}

//Tested
char* element_get_lowCase(){
	char* elements = malloc(LETTERS_COUNT);
	for(int i = 0; i < LETTERS_COUNT; elements[i] = 'a' + i, i++);
	return elements;
}

//Tested
char* element_get_numbers(){
	char* elements = malloc(10);
	for(int i = 0; i < 10; elements[i] = '0' + i, i++);
	return elements;
}

//Semi - tested
void* element_get_num(double initial, double final, t_int size){
	// printf("\nFrom %.f telement_get_numo %.f\n", initial, final);
	if (final < initial){
		//ERROR
		// printf("Final less than initial\n");
		return NULL;
	}	

	// printf("Final greater than initial\n");

	bool is_signed;

	if(size >= UI8 && size <= UI64){
		is_signed = false;
		// printf("Type is signed\n");
	}

	else if(size >= I8 && size <= I64){
		is_signed = true;

		// printf("Type is unsigned\n");
	}

	else{
		//ERROR
		return NULL;	
	}

	u_int8_t bytes;

	switch(size){
	case UI8: case I8:
		bytes = 1;
		break;

	case UI16: case I16:
		bytes = 2;
		break;

	case UI32: case I32:
		bytes = 4;
		break;

	default:
		//ERROR
		return NULL;
		break;
	}

	u_int8_t bits = bytes * 8;

	// printf("Type has %d bits\n", bits);

	double max;
	double min;

	if(is_signed){
		min = pow(2, -bits);
		bits--;
		max = pow(2, bits) - 1;
	}

	else{
		min = 0;
		max = pow(2, bits) - 1;
	}

	// printf("Initial %.f\nMin:    %.f\n", initial, min);
	// printf("Final %.f\nMax:  %.f\n", final, max);			
	if( (initial < min) || (final > max) ){
		// printf("Out of range\n");
		//ERROR
		return NULL;
	}

	double count = final - initial + 1;

	void* elements = malloc(bytes * count);

	switch(size){
	case UI8:
		for (u_int8_t i = 0; i < count; ((u_int8_t*)elements) [i] = (u_int8_t)initial + i, ++i);
		break;

	case I8:
		for (int8_t i = 0; i < count; ((int8_t*)elements) [i] = (int8_t)initial + i, ++i);
		break;

	case UI16:
		for (u_int16_t i = 0; i < count; ((u_int16_t*)elements) [i] = (u_int16_t)initial + i, ++i);
		break;

	case I16:
		for (int16_t i = 0; i < count; ((int16_t*)elements) [i] = (int16_t)initial + i, ++i);
		break;

	case UI32:
		for (u_int32_t i = 0; i < count; ((u_int32_t*)elements) [i] = (u_int32_t)initial + i, ++i);
		break;

	case I32:
		for (int32_t i = 0; i < count; ((int32_t*)elements) [i] = (int32_t)initial + i, ++i);
		break;

	default:
		return NULL;
		break;
	}

	return elements;
}
