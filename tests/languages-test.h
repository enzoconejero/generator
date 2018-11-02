
#ifndef TESTS_ALPHABETS_TEST_H_
#define TESTS_ALPHABETS_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "../language.h"
#include "../element.h"

//#define LETTERS_COUNT ('z' - 'a' + 1)

void testCharEqual();
void testInt8Equal();
void testLanguageCreate();
void testSetEquals();
void testSetElementsInEmptyLanguage();
void testSetElementsInNoEmptyLanguage();
void testSetRepeatedElementsInNoEmptyLanguage();
void testAddElementsInEmptyLanguage();
void testAddElementsInNotEmptyLanguage();
void testAddRepeatedElementsInNotEmptyLanguage();
void testGetElementAtIndex();

#endif /* TESTS_ALPHABETS_TEST_H_ */
