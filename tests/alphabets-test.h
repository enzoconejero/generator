
#ifndef TESTS_ALPHABETS_TEST_H_
#define TESTS_ALPHABETS_TEST_H_

#include <stdio.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "../alphabet.h"
#include "../language.h"

//#define LETTERS_COUNT ('z' - 'a' + 1)

void testAlphabetCreator();
void testSetElemts();
void testAddElemtsInEmptyAlphabet();
void testAddElemtsInNotEmptyAlphabet();
void testGetLowCasesElements();
void testGetUpCasesElements();
void testGetNumbersElements();

#endif /* TESTS_ALPHABETS_TEST_H_ */
