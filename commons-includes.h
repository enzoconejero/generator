
#ifndef COMMONS_INCLUDES_H_
#define COMMONS_INCLUDES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define LETTERS_COUNT ('z' - 'a' + 1)
#define NL printf("\n")

static bool debug_mode = false;

typedef struct{
	//General stuff
	void* word;
	int* indexes;
	int current_length;
	//Language stuff
	void* elements;
	void* last_element;
	size_t element_size;
	size_t element_count;
	bool (*equals)(void* a, void*b);
}t_gcb;

typedef struct{
	size_t elements_count;
	size_t elements_size;
	void* elements;
	void* last_element;
	bool (*equals)(void*, void*);
	void (*print)(t_gcb*);
	bool (*filter)(t_gcb*);
}t_language;

#include "logger.h"

#endif /* COMMONS_INCLUDES_H_ */
