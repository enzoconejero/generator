
#ifndef ELEMENTS_TEST_H
#define ELEMENTS_TEST_H

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "../element.h"

void testGetLowCasesElements();
void testGetUpCasesElements();
void testGetNumbersElements();
void testGetNumFailWhenFinalLessThanInitial();
void testGetNumFailWhenCountGreaterThanMax();
void testGetNumFrom0to100();

#endif 
