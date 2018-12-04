
#ifndef FILTER_H
#define FILTER_H

#include "commons-includes.h"
#include "language.h"

unsigned long total;
unsigned long mill;

bool filter_default(t_gcb* gcb);
bool filter_name(t_gcb* gcb);
bool filter_sudoku(t_gcb* gcb);

#endif
