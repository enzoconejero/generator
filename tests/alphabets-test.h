
#ifndef TESTS_ALPHABETS_TEST_H_
#define TESTS_ALPHABETS_TEST_H_

#include <stdio.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "../alphabet.h"

//#define LETTERS_COUNT ('z' - 'a' + 1)

void testGetLowCasesElements();
void testGetUpCasesElements();
void testGetNumbersElements();
void testCharEqual();
void testAlphabetCreator();
void testSetEquals();

void testSetElements();

void testAddElemtsInEmptyAlphabet();
void testAddNewElemtsInNotEmptyAlphabet();

#endif /* TESTS_ALPHABETS_TEST_H_ */
