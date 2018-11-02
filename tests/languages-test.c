
#include "languages-test.h"

/*Test order:
 * 1. Get elements -- ok
 * 2. Equal
 * 3. Create language
 * 4  Filter repeated elements
 * 4. Set elements in empty language
 * 5. Create language
 * 6. Set elements in no empty language
 * 7. Add elements in empty language
 * 8. Add new elements in empty language
 * 9. Add repeated elements in no empty language
 * 10. Add mixed elements in no empty language
 * */

void testLanguageAlphaNumeric(){
	t_language* language = language_create();
	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, sizeof(char));
	language_add_element(language, element_get_upCase(), LETTERS_COUNT, sizeof(char));
	language_add_element(language, element_get_numbers(), 10, sizeof(char));

	CU_ASSERT_EQUAL(language->elements_count, LETTERS_COUNT*2 + 10);

	for(char i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*)language->elements)[i] , 'a' + i );
	}
	for(char i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*)language->elements)[i+LETTERS_COUNT] , 'A' + i );
	}
	for(char i = 0; i < 10; i++){
		CU_ASSERT_EQUAL( ((char*)language->elements)[i+LETTERS_COUNT*2] , '0' + i );
	}
}

void testCharEqual(){
	char a, b;
	a = 'a';
	b = 'a';
	CU_ASSERT_TRUE(equals_char( &a, &b) );
}

void testInt8Equal(){
	int8_t a, b;
	a = 1;
	b = 1;
	CU_ASSERT_TRUE(equals_int8( &a, &b) );
}

void testSetEquals(){
	t_language* language = language_create();
	language_set_equal(language,&equals_char);
	char c1, c2;
	c1 = 'a';
	c2 = 'a';
	CU_ASSERT_TRUE( (*(language->equals)) (&c1, &c2) );

	c1 = 'a';
	c2 = 'A';
	CU_ASSERT_FALSE( (*(language->equals)) (&c1, &c2) );

	c1 = 'A';
	c2 = 65;
	CU_ASSERT_TRUE( (*(language->equals)) (&c1, &c2) );

	c1 = '1';
	c2 = '2';
	CU_ASSERT_FALSE( (*(language->equals)) (&c1, &c2) );

	c1 = '\0';
	c2 = '\0';
	CU_ASSERT_TRUE( (*(language->equals)) (&c1, &c2) );

	language_set_equal(language,&equals_int8);
	int8_t i1, i2;
	i1 = 'a';
	i2 = 'a';
	CU_ASSERT_TRUE( (*(language->equals)) (&i1, &i2) );

	i1 = 'a';
	i2 = 'A';
	CU_ASSERT_FALSE( (*(language->equals)) (&i1, &i2) );

	i1 = 'A';
	i2 = 65;
	CU_ASSERT_TRUE( (*(language->equals)) (&i1, &i2) );

	i1 = '1';
	i2 = '2';
	CU_ASSERT_FALSE( (*(language->equals)) (&i1, &i2) );

	i1 = 0;
	i2 = -0;
	CU_ASSERT_TRUE( (*(language->equals)) (&i1, &i2) );
}

void testSetElementsInEmptyLanguage(){
	t_language* language = language_create();
	size_t elements_to_add = 10;
	language_set_equal(language,&equals_int8);
	int8_t* elements = malloc(sizeof(int8_t) * elements_to_add);
	for(int i = 0; i < elements_to_add; i++){
		elements[i] = i;
	}

	language_set_element(language, elements, elements_to_add, sizeof(int8_t));

	for(int i = 0; i < elements_to_add; i++){
		CU_ASSERT_EQUAL( ((int8_t*) (language->elements))[i], i);
	}

	CU_ASSERT_EQUAL(language->elements_count, elements_to_add);
	CU_ASSERT_EQUAL(language->elements_size, sizeof(int8_t));
	CU_ASSERT_EQUAL( *((int8_t*)(language->last_element)), elements_to_add - 1);

	language_destroy(language);
}

void testSetElementsInNoEmptyLanguage(){
	t_language* language = language_create();
	size_t initial_elements_count = 10;
	language_set_equal(language,&equals_int8);
	int8_t* initial_elements = malloc(sizeof(int8_t) * initial_elements_count);
	for(int i = 0; i < initial_elements_count; i++){
		initial_elements[i] = i;
	}

	language_set_element(language, initial_elements, initial_elements_count, sizeof(int8_t));
	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, 1);

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*) (language->elements))[i], 'a' + i);
	}

	CU_ASSERT_EQUAL(language->elements_count, LETTERS_COUNT);
	CU_ASSERT_EQUAL(language->elements_size, sizeof(char));
	CU_ASSERT_EQUAL( *((char*)(language->last_element)), 'z');

	language_destroy(language);
}

void testSetRepeatedElementsInNoEmptyLanguage(){
	t_language* language = language_create();
	language_set_equal(language,&equals_int8);
	size_t initial_elements_count = 10;
	srand(time(NULL));
	int8_t* initial_elements = malloc(sizeof(int8_t) * initial_elements_count);
	for(int i = 0; i < initial_elements_count; i++){
		initial_elements[i] = rand() % 3 + 1;
	}

	language_set_element(language, initial_elements, initial_elements_count, sizeof(int8_t));

	CU_ASSERT_EQUAL(language->elements_count, 3);
	CU_ASSERT_EQUAL(language->elements_size, sizeof(int8_t));

	bool* has_all_numbers = (bool*) malloc(sizeof(bool));

	for(int i = 0; i < 3; i++ ){
		int8_t actual = ((int8_t*) language->elements)[i];
		if(actual == 1){
			has_all_numbers[0] = true;
		}
		else if(actual == 2){
			has_all_numbers[1] = true;
		}
		else if(actual == 3){
			has_all_numbers[2] = true;
		}
	}

	for(int i = 0; i < 3; i++){
		CU_ASSERT_TRUE( has_all_numbers[i] );
	}
	language_destroy(language);
}

void testAddElementsInEmptyLanguage(){
	t_language* language = language_create();
	language_set_equal(language,&equals_char);

	language_add_element(language, element_get_lowCase(), LETTERS_COUNT, sizeof(char));

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*) (language->elements))[i], 'a' + i);
	}

	CU_ASSERT_EQUAL(language->elements_count, LETTERS_COUNT);
	CU_ASSERT_EQUAL(language->elements_size, sizeof(char));
	CU_ASSERT_EQUAL( *((int8_t*)(language->last_element)), 'z');

	language_destroy(language);
}

void testAddElementsInNotEmptyLanguage(){
	t_language* language = language_create();
	language_set_equal(language,&equals_char);

	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, sizeof(char));
	language_add_element(language, element_get_upCase(), LETTERS_COUNT, sizeof(char));

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*) (language->elements))[i], 'a' + i);
		CU_ASSERT_EQUAL( ((char*) (language->elements))[i + LETTERS_COUNT], 'A' + i);
	}

	CU_ASSERT_EQUAL(language->elements_count, LETTERS_COUNT*2);
	CU_ASSERT_EQUAL(language->elements_size, sizeof(char));
	CU_ASSERT_EQUAL( *((char*)(language->last_element)), 'Z');

	language_destroy(language);
}

void testAddRepeatedElementsInNotEmptyLanguage(){
	t_language* language = language_create();
	language_set_equal(language,&equals_char);

	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, sizeof(char));
	language_add_element(language, element_get_upCase(), LETTERS_COUNT, sizeof(char));
	language_add_element(language, element_get_upCase(), LETTERS_COUNT, sizeof(char));
	language_add_element(language, element_get_upCase(), LETTERS_COUNT, sizeof(char));

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*) (language->elements))[i], 'a' + i);
		CU_ASSERT_EQUAL( ((char*) (language->elements))[i + LETTERS_COUNT], 'A' + i);
	}

	CU_ASSERT_EQUAL(language->elements_count, LETTERS_COUNT*2);
	CU_ASSERT_EQUAL(language->elements_size, sizeof(char));
	CU_ASSERT_EQUAL( *((char*)(language->last_element)), 'Z');

	language_destroy(language);
}

void testGetElementAtIndex(){
	t_language* language = language_create();
	language_set_equal(language,&equals_char);	
	language_set_element(language, element_get_lowCase(), LETTERS_COUNT, sizeof(char));

	for (int i = 0; i < LETTERS_COUNT; ++i){
		CU_ASSERT_EQUAL( *(char*) language_get_element_at(language, i), 'a' + i);
	}
}

void testLanguageCreate(){
	t_language* language = language_create();
	CU_ASSERT( language != NULL );
	CU_ASSERT( language->elements == NULL );
	CU_ASSERT( language->elements_count == 0 );
	CU_ASSERT( language->elements_size == 0 );
	CU_ASSERT( language->last_element == NULL);
	CU_ASSERT( language->equals == NULL);
	language_destroy(language);
}