
#ifndef GENERATOR_H
#define GENERATOR_H

#include "commons-includes.h"
#include "language.h"

typedef struct{
	t_language* language;
	t_gcb* gcb;
	bool (*stop_condition)(t_gcb*);
	bool (*filter)(t_gcb*);
	void (*printer)(t_gcb*);
	void (*persister)(t_gcb*);
}t_generator;

t_gcb* gcb_create(t_language* language);
t_generator* generator_create(t_language* language);
void generator_set_filter(t_generator* generator, bool (*filter)(t_gcb*) );
void generator_set_stop_condition(t_generator* generator, bool (*stop_condition)(t_gcb*) );
void generator_set_persister(t_generator* generator, void (*persister)(t_gcb*) );
void generate(t_generator* generator);

#endif