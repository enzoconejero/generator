
#include "equal.h"

//Tested
bool equals_char(void* c1, void* c2){
	return *((char*) c1) == *((char*) c2);
}

//Tested
bool equals_int8(void* c1, void* c2){
	return (*((int8_t*) c1)) == (*((int8_t*) c2));
}

//Tested
bool equals_int16(void* c1, void* c2){
	return (*((int16_t*) c1)) == (*((int16_t*) c2));
}

//Tested
bool equals_int32(void* c1, void* c2){
	return (*((int32_t*) c1)) == (*((int32_t*) c2));
}

//Tested
bool equals_uint8(void* c1, void* c2){
	return (*((u_int8_t*) c1)) == (*((u_int8_t*) c2));
}

//Tested
bool equals_uint16(void* c1, void* c2){
	return (*((u_int16_t*) c1)) == (*((u_int16_t*) c2));
}

//Tested
bool equals_uint32(void* c1, void* c2){
	return (*((u_int32_t*) c1)) == (*((u_int32_t*) c2));
}

//Tested
bool equals_double(void* c1, void* c2){
	return (*((double*) c1)) == (*((double*) c2));
}
