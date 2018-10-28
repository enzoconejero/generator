
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

//To correct
void* element_get_num(double initial, double final, t_int size){
	printf("\nFrom %.f to %.f\n", initial, final);
	if (final < initial){
		//ERROR
		printf("Final less than initial\n");
		return NULL;
	}	

	printf("Final greater than initial\n");

	bool is_signed;

	if(size >= UI8 && size <= UI64){
		is_signed = false;
		printf("Type is signed\n");
	}

	else if(size >= I8 && size <= I64){
		is_signed = true;

		printf("Type is unsigned\n");
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

	case UI64: case I64:
		bytes = 8;
		break;

	default:
		return NULL;
		break;
	}

	u_int8_t bits = bytes * 8;

	printf("Type has %d bits\n", bits);

	double max;
	double min;

	printf("1\n");
	if(is_signed){
		min = pow(2, -bits);
		bits--;
		max = pow(2, bits) - 1;
	}

	else{
		min = 0;
		max = pow(2, bits) - 1;
	}

	printf("Initial %.f\nMin:    %.f\n", initial, min);
	printf("Final %.f\nMax:  %.f\n", final, max);			
	if( (initial < min) || (final > max) ){
		printf("Out of range\n");
		return NULL;
	}

	printf("15\n");

	double count = final - initial + 1;

	void* elements = malloc(bytes * count );

	printf("20\n");

	switch(size){
	case UI8:{

		u_int8_t num;

		for (double i = 0; i < count; i++){
			num = (u_int8_t)i;
			memcpy(elements + (u_int64_t)i * bytes, &num, bytes);
		}

		break;
	}//End of case

	case I8:{

		int8_t num;

		for (double i = 0; i < count; i++){
			num = (int8_t)i;
			memcpy(elements + (u_int64_t)i * bytes, &num, bytes);
		}

		break;
	}//End of case

	case UI16:{

		u_int64_t num;

		for (double i = 0; i < count; i++){
			num = (u_int64_t)i;
			memcpy(elements + (u_int64_t)i * bytes, &num, bytes);
		}

		break;
	}//End of case

	case I16:{

		int16_t num;

		for (double i = 0; i < count; i++){
			num = (int16_t)i;
			memcpy(elements + (u_int64_t)i * bytes, &num, bytes);
		}

		break;
	}//End of case

	case UI32:{

		u_int32_t num;

		for (double i = 0; i < count; i++){
			num = (u_int32_t)i;
			memcpy(elements + (u_int64_t)i * bytes, &num, bytes);
		}

		break;
	}//End of case

	case I32:{

		int32_t num;

		for (double i = 0; i < count; i++){
			num = (int32_t)i;
			memcpy(elements + (u_int64_t)i * bytes, &num, bytes);
		}

		break;
	}//End of case

	case UI64:{
		printf("30\n");
		u_int64_t num;

		for (double i = 0; i < count; i++){
			// printf("%.f\n", 50+i);
			num = (u_int64_t)i;
			memcpy(elements + (u_int64_t)i * bytes, &num, bytes);
		}

		break;
	}//End of case

	case I64:{

		int64_t num;

		for (double i = 0; i < count; i++){
			num = (int64_t)i;
			memcpy(elements + (u_int64_t)i * bytes, &num, bytes);
		}

		break;
	}//End of case

	default:
		return NULL;
		break;
	}
}
