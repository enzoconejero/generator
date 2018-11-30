
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
	if (final < initial){
		//ERROR
		log_screen("Final less than initial");
		return NULL;
	}	

	log_screen("Final greater than initial");

	bool is_signed;

	if(size >= UI8 && size <= UI64){
		is_signed = false;
		log_screen("Type is signed");
	}

	else if(size >= I8 && size <= I64){
		is_signed = true;

		log_screen("Type is unsigned");
	}

	else{
		log_screen("Unrecognized type");
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
		log_screen("Unrecognized type");
		return NULL;
		break;
	}

	u_int8_t bits = bytes * 8;

	log_screen("Type has %d bits", bits);

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

	log_screen("Initial %.f\nMin:    %.f", initial, min);
	log_screen("Final %.f\nMax:  %.f", final, max);			
	if( (initial < min) || (final > max) ){
		log_screen("Out of range");
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

char* element_get_punctuation_marks(){
	char* elements = malloc(13);
	elements[0] = '.';
	elements[1] = ',';
	elements[2] = ';';
	elements[3] = ':';
	elements[4] = '-';
	elements[5] = '(';
	elements[6] = ')';
	elements[7] = '!';
	elements[8] = '?';
	elements[9] = '\'';
	elements[10] = '>';
	elements[11] = '<';
	elements[12] = '"';
	elements[13] = ' ';
	return elements;
}

char* element_get_c_special(){
	char* elements = malloc(26);
	elements[0] = '.';
	elements[1] = ',';
	elements[2] = ';';
	elements[3] = ':';
	elements[4] = '"';
	elements[5] = '\'';
	elements[6] = '\\';
	elements[7] = '_';
	elements[8] = '!';
	elements[9] = '?';
	elements[10] = '&';
	elements[11] = '|';
	elements[12] = '+';
	elements[13] = '-';
	elements[14] = '*';
	elements[15] = '=';
	elements[16] = '/';
	elements[17] = '(';
	elements[18] = ')';
	elements[19] = '[';
	elements[20] = ']';
	elements[21] = '{';
	elements[22] = '}';
	elements[23] = '<';
	elements[24] = '>';
	elements[25] = ' ';
	return elements;
}