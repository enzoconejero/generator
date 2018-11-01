
#ifndef TESTS_ALPHABETS_TEST_H_
#define TESTS_ALPHABETS_TEST_H_

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "../alphabet.h"
#include "../element.h"

//#define LETTERS_COUNT ('z' - 'a' + 1)

void testCharEqual();
void testInt8Equal();
void testAlphabetCreate();
void testSetEquals();
void testSetElementsInEmptyAlphabet();
void testSetElementsInNoEmptyAlphabet();
void testSetRepeatedElementsInNoEmptyAlphabet();
void testAddElementsInEmptyAlphabet();
void testAddElementsInNotEmptyAlphabet();
void testAddRepeatedElementsInNotEmptyAlphabet();
void testGetElementAtIndex();

#endif /* TESTS_ALPHABETS_TEST_H_ */
