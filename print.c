
#include "print.h"

void print_char(void* element){
	printf("%c", *(char*)element);
}

void print_int8(void* element){
	printf("%d", *(int8_t*)element);
}

void print_int16(void* element){
	printf("%d", *(int16_t*)element);
}

void print_int32(void* element){
	printf("%d", *(int32_t*)element);
}

void print_uint8(void* element){
	printf("%d", *(u_int8_t*)element);
}

void print_uint16(void* element){
	printf("%d", *(u_int16_t*)element);
}

void print_uint32(void* element){
	printf("%d", *(u_int32_t*)element);
}
