
#include "alphabets-test.h"

/*Test order:
 * 1. Get elements -- ok
 * 2. Equal
 * 3. Create alphabet
 * 4  Filter repeated elements
 * 4. Set elements in empty alphabet
 * 5. Create alphabet
 * 6. Set elements in no empty alphabet
 * 7. Add elements in empty alphabet
 * 8. Add new elements in empty alphabet
 * 9. Add repeated elements in no empty alphabet
 * 10. Add mixed elements in no empty alphabet
 * */

void testAlphabetAlphaNumeric(){
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_element(alphabet, element_get_lowCase(), LETTERS_COUNT, sizeof(char));
	alphabet_add_element(alphabet, element_get_upCase(), LETTERS_COUNT, sizeof(char));
	alphabet_add_element(alphabet, element_get_numbers(), 10, sizeof(char));

	CU_ASSERT_EQUAL(alphabet->elements_count, LETTERS_COUNT*2 + 10);

	for(char i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*)alphabet->elements)[i] , 'a' + i );
	}
	for(char i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*)alphabet->elements)[i+LETTERS_COUNT] , 'A' + i );
	}
	for(char i = 0; i < 10; i++){
		CU_ASSERT_EQUAL( ((char*)alphabet->elements)[i+LETTERS_COUNT*2] , '0' + i );
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
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet,&equals_char);
	char c1, c2;
	c1 = 'a';
	c2 = 'a';
	CU_ASSERT_TRUE( (*(alphabet->equals)) (&c1, &c2) );

	c1 = 'a';
	c2 = 'A';
	CU_ASSERT_FALSE( (*(alphabet->equals)) (&c1, &c2) );

	c1 = 'A';
	c2 = 65;
	CU_ASSERT_TRUE( (*(alphabet->equals)) (&c1, &c2) );

	c1 = '1';
	c2 = '2';
	CU_ASSERT_FALSE( (*(alphabet->equals)) (&c1, &c2) );

	c1 = '\0';
	c2 = '\0';
	CU_ASSERT_TRUE( (*(alphabet->equals)) (&c1, &c2) );

	alphabet_set_equal(alphabet,&equals_int8);
	int8_t i1, i2;
	i1 = 'a';
	i2 = 'a';
	CU_ASSERT_TRUE( (*(alphabet->equals)) (&i1, &i2) );

	i1 = 'a';
	i2 = 'A';
	CU_ASSERT_FALSE( (*(alphabet->equals)) (&i1, &i2) );

	i1 = 'A';
	i2 = 65;
	CU_ASSERT_TRUE( (*(alphabet->equals)) (&i1, &i2) );

	i1 = '1';
	i2 = '2';
	CU_ASSERT_FALSE( (*(alphabet->equals)) (&i1, &i2) );

	i1 = 0;
	i2 = -0;
	CU_ASSERT_TRUE( (*(alphabet->equals)) (&i1, &i2) );
}

void testAlphabetCreate(){
	t_alphabet* alphabet = alphabet_create();
	CU_ASSERT( alphabet != NULL );
	CU_ASSERT( alphabet->elements == NULL );
	CU_ASSERT( alphabet->elements_count == 0 );
	CU_ASSERT( alphabet->elements_size == 0 );
	CU_ASSERT( alphabet->last_element == NULL);
	CU_ASSERT( alphabet->equals == NULL);
	alphabet_destroy(alphabet);
}

void testSetElementsInEmptyAlphabet(){
	t_alphabet* alphabet = alphabet_create();
	srand(time(NULL));
	size_t elements_to_add = 10;
	alphabet_set_equal(alphabet,&equals_int8);
	int8_t* elements = malloc(sizeof(int8_t) * elements_to_add);
	for(int i = 0; i < elements_to_add; i++){
		elements[i] = (int8_t)i;
	}
	alphabet_set_element(alphabet, elements, elements_to_add, sizeof(int8_t));

	for(int i = 0; i < elements_to_add; i++){
		CU_ASSERT_EQUAL( ((int8_t*) (alphabet->elements))[i], i);
	}

	CU_ASSERT_EQUAL(alphabet->elements_count, elements_to_add);
	CU_ASSERT_EQUAL(alphabet->elements_size, sizeof(int8_t));
	CU_ASSERT_EQUAL( *((int8_t*)(alphabet->last_element)), elements_to_add - 1);

	alphabet_destroy(alphabet);
}

void testSetElementsInNoEmptyAlphabet(){
	t_alphabet* alphabet = alphabet_create();
	size_t initial_elements_count = 10;
	alphabet_set_equal(alphabet,&equals_int8);
	int8_t* initial_elements = malloc(sizeof(int8_t) * initial_elements_count);
	for(int i = 0; i < initial_elements_count; i++){
		initial_elements[i] = i;
	}

	alphabet_set_element(alphabet, initial_elements, initial_elements_count, sizeof(int8_t));
	alphabet_set_element(alphabet, element_get_lowCase(), LETTERS_COUNT, 1);

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*) (alphabet->elements))[i], 'a' + i);
	}

	CU_ASSERT_EQUAL(alphabet->elements_count, LETTERS_COUNT);
	CU_ASSERT_EQUAL(alphabet->elements_size, sizeof(char));
	CU_ASSERT_EQUAL( *((char*)(alphabet->last_element)), 'z');

	alphabet_destroy(alphabet);
}

void testSetRepeatedElementsInNoEmptyAlphabet(){
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet,&equals_int8);
	size_t initial_elements_count = 10;
	srand(time(NULL));
	int8_t* initial_elements = malloc(sizeof(int8_t) * initial_elements_count);
	for(int i = 0; i < initial_elements_count; i++){
		initial_elements[i] = rand() % 3 + 1;
	}

	alphabet_set_element(alphabet, initial_elements, initial_elements_count, sizeof(int8_t));

	CU_ASSERT_EQUAL(alphabet->elements_count, 3);
	CU_ASSERT_EQUAL(alphabet->elements_size, sizeof(int8_t));

	bool* has_all_numbers = (bool*) malloc(sizeof(bool));

	for(int i = 0; i < 3; i++ ){
		int8_t actual = ((int8_t*) alphabet->elements)[i];
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
	alphabet_destroy(alphabet);
}

void testAddElementsInEmptyAlphabet(){
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet,&equals_char);

	alphabet_add_element(alphabet, element_get_lowCase(), LETTERS_COUNT, sizeof(char));

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*) (alphabet->elements))[i], 'a' + i);
	}

	CU_ASSERT_EQUAL(alphabet->elements_count, LETTERS_COUNT);
	CU_ASSERT_EQUAL(alphabet->elements_size, sizeof(char));
	CU_ASSERT_EQUAL( *((int8_t*)(alphabet->last_element)), 'z');

	alphabet_destroy(alphabet);
}

void testAddElementsInNotEmptyAlphabet(){
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet,&equals_char);

	alphabet_set_element(alphabet, element_get_lowCase(), LETTERS_COUNT, sizeof(char));
	alphabet_add_element(alphabet, element_get_upCase(), LETTERS_COUNT, sizeof(char));

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*) (alphabet->elements))[i], 'a' + i);
		CU_ASSERT_EQUAL( ((char*) (alphabet->elements))[i + LETTERS_COUNT], 'A' + i);
	}

	CU_ASSERT_EQUAL(alphabet->elements_count, LETTERS_COUNT*2);
	CU_ASSERT_EQUAL(alphabet->elements_size, sizeof(char));
	CU_ASSERT_EQUAL( *((char*)(alphabet->last_element)), 'Z');

	alphabet_destroy(alphabet);
}

void testAddRepeatedElementsInNotEmptyAlphabet(){
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet,&equals_char);

	alphabet_set_element(alphabet, element_get_lowCase(), LETTERS_COUNT, sizeof(char));
	alphabet_add_element(alphabet, element_get_upCase(), LETTERS_COUNT, sizeof(char));
	alphabet_add_element(alphabet, element_get_upCase(), LETTERS_COUNT, sizeof(char));
	alphabet_add_element(alphabet, element_get_upCase(), LETTERS_COUNT, sizeof(char));

	for(int i = 0; i < LETTERS_COUNT; i++){
		CU_ASSERT_EQUAL( ((char*) (alphabet->elements))[i], 'a' + i);
		CU_ASSERT_EQUAL( ((char*) (alphabet->elements))[i + LETTERS_COUNT], 'A' + i);
	}

	CU_ASSERT_EQUAL(alphabet->elements_count, LETTERS_COUNT*2);
	CU_ASSERT_EQUAL(alphabet->elements_size, sizeof(char));
	CU_ASSERT_EQUAL( *((char*)(alphabet->last_element)), 'Z');

	alphabet_destroy(alphabet);
}

void testGetElementAtIndex(){
	t_alphabet* alphabet = alphabet_create();
	alphabet_set_equal(alphabet,&equals_char);	
	alphabet_set_element(alphabet, element_get_lowCase(), LETTERS_COUNT, sizeof(char));

	for (int i = 0; i < LETTERS_COUNT; ++i){
		CU_ASSERT_EQUAL( *(char*) alphabet_get_element_at(alphabet, i), 'a' + i);
	}
}