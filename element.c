
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
void* element_get_num(int64_t initial, int64_t final, t_int size){
	printf("1\n");
	if (final < initial){
		//ERROR
		return NULL;
	}

	u_int64_t count = final - initial + 1;
	double max_count;
	int bytes;
	printf("1\n");

	switch(size){
	case UI8 :{
		bytes = 1;
		max_count = pow(2,bytes * 8);

		if( count <= max_count && final <= max_count ){
			u_int8_t* elements = malloc(count * bytes);

			memset(elements, 0, count * bytes);

			for (u_int8_t i = 0; i < count; ++i){
				u_int8_t num = initial + i;
				memcpy(elements + i * bytes, &num, bytes);
			}

			printf("Return u int 8 elements \n");
			return elements;
		}

		else{
			//ERROR-OVERFLOW
			return NULL;
		}
	}

	case UI16 :{
		bytes = 2;
		max_count = pow(2,bytes * 8);

		if( count <= max_count && final <= max_count){
			u_int16_t* elements = malloc(count * bytes);

			memset(elements, 0, count * bytes);

			for (u_int16_t i = 0; i < count; ++i){
				elements[i] = initial + i;
			}

			return elements;
		}

		else{
			//ERROR-OVERFLOW
			return NULL;
		}
	}

	case UI32 :{
		bytes = 4;
		max_count = pow(2,bytes * 8);

		if( count <= max_count && final <= max_count){
			u_int32_t* elements = malloc( count * bytes );

			memset(elements, 0, count * bytes);

			for (u_int32_t i = 0; i < count; ++i){
				elements[i] = initial + i;
			}

			return elements;
		}

		else{
			//ERROR-OVERFLOW
			return NULL;
		}
	}

	case UI64 :{
		bytes = 8;
		max_count = pow(2,bytes * 8);

		if( count <= max_count && final <= max_count){
			u_int64_t* elements = malloc( count * bytes );

			memset(elements, 0, count * bytes);

			for (u_int64_t i = 0; i < count; ++i){
				elements[i] = initial + i;
			}

			return elements;
		}

		else{
			//ERROR-OVERFLOW
			return NULL;
		}
	}

	case I8 :{
		bytes = 1;
		max_count = pow(2, bytes * 8 - 1);
		printf("MAX: %f\n", max_count);

		if( count <= max_count && final <= max_count){
			int8_t* elements = malloc( count * bytes);

			memset(elements, 0, count * bytes);

			for (int8_t i = 0; i < count; ++i){
				elements[i] = initial + i;
			}

			return elements;
		}

		else{
			//ERROR-OVERFLOW
			return NULL;
		}
	}

	case I16 :{
		bytes = 2;
		max_count = pow(2,bytes * 8 - 1);

		if( count <= max_count && final <= max_count){
			int16_t* elements = malloc( count * bytes );

			memset(elements, 0, count * bytes);

			for (int16_t i = 0; i < count; ++i){
				elements[i] = initial + i;
			}

			return elements;
		}

		else{
			//ERROR-OVERFLOW
			return NULL;
		}
	}

	case I32 :{
		bytes = 4;
		max_count = pow(2,bytes * 8 - 1);

		if( count <= max_count && final <= max_count){
			int32_t* elements = malloc( count * bytes );

			memset(elements, 0, count * bytes);

			for (int32_t i = 0; i < count; ++i){
				elements[i] = initial + i;
			}

			return elements;
		}

		else{
			//ERROR-OVERFLOW
			return NULL;
		}
	}

	case I64 :{
		bytes = 8;
		max_count = pow(2,bytes * 8 - 1);

		if( count <= max_count && final <= max_count){
			int64_t* elements = malloc( count * bytes );

			memset(elements, 0, count * bytes);

			for (int64_t i = 0; i < count; ++i){
				elements[i] = initial + i;
			}

			return elements;
		}

		else{
			//ERROR-OVERFLOW
			return NULL;
		}
	}

	default:
		printf("There are not a valid size\n");
		return NULL;
		break;
	}
}
