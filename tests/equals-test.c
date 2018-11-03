
#include "equals-test.h"

// bool equals_char(void* c1, void* c2);
// bool equals_int8(void* c1, void* c2);
// bool equals_int16(void* c1, void* c2);
// bool equals_int32(void* c1, void* c2);
// bool equals_uint8(void* c1, void* c2);
// bool equals_uint16(void* c1, void* c2);
// bool equals_uint32(void* c1, void* c2);
// bool equals_double(void* c1, void* c2);


void testChar(){
	char a, b;

	a = 'a';
	b = 'a';
	CU_ASSERT( equals_int8(&a, &b) );

	a = 'a';
	b = 'b';
	CU_ASSERT( !equals_int8(&a, &b) );

	a = 'a';
	b = 'A';
	CU_ASSERT( !equals_int8(&a, &b) );

	a = '\0';
	b = '\t';
	CU_ASSERT( !equals_int8(&a, &b) );
}

void testInt8(){
	int8_t a, b;

	a = 1;
	b = 1;
	CU_ASSERT( equals_int8(&a, &b) );

	a = 0;
	b = -0;
	CU_ASSERT( equals_int8(&a, &b) );	

	a = 0;
	b = -0;
	CU_ASSERT( equals_int8(&a, &b) );	

	a = 10;
	b = 20;
	CU_ASSERT( !equals_int8(&a, &b) );
}

void testInt16(){
	int16_t a, b;

	a = 1;
	b = 1;
	CU_ASSERT( equals_int16(&a, &b) );

	a = 0;
	b = -0;
	CU_ASSERT( equals_int16(&a, &b) );	

	a = 0;
	b = -0;
	CU_ASSERT( equals_int16(&a, &b) );	

	a = 10;
	b = 20;
	CU_ASSERT( !equals_int16(&a, &b) );
}

void testInt32(){
	int32_t a, b;

	a = 1;
	b = 1;
	CU_ASSERT( equals_int32(&a, &b) );

	a = 0;
	b = -0;
	CU_ASSERT( equals_int32(&a, &b) );	

	a = 0;
	b = -0;
	CU_ASSERT( equals_int32(&a, &b) );	

	a = 10;
	b = 20;
	CU_ASSERT( !equals_int32(&a, &b) );	
}

void testuInt8(){
	int8_t a, b;

	a = 1;
	b = 1;
	CU_ASSERT( equals_uint8(&a, &b) );

	a = 0;
	b = -0;
	CU_ASSERT( equals_uint8(&a, &b) );	

	a = 0;
	b = -0;
	CU_ASSERT( equals_uint8(&a, &b) );	

	a = 10;
	b = 20;
	CU_ASSERT( !equals_uint8(&a, &b) );
}

void testuInt16(){
	int16_t a, b;

	a = 1;
	b = 1;
	CU_ASSERT( equals_uint16(&a, &b) );

	a = 0;
	b = -0;
	CU_ASSERT( equals_uint16(&a, &b) );	

	a = 0;
	b = -0;
	CU_ASSERT( equals_uint16(&a, &b) );	

	a = 10;
	b = 20;
	CU_ASSERT( !equals_uint16(&a, &b) );
}

void testuInt32(){
	int32_t a, b;

	a = 1;
	b = 1;
	CU_ASSERT( equals_uint32(&a, &b) );

	a = 0;
	b = -0;
	CU_ASSERT( equals_uint32(&a, &b) );	

	a = 0;
	b = -0;
	CU_ASSERT( equals_uint32(&a, &b) );	

	a = 10;
	b = 20;
	CU_ASSERT( !equals_uint32(&a, &b) );
}

void testDouble(){
	double a, b;

	a = 0;
	b = 0.0;
	CU_ASSERT( equals_double(&a, &b) );

	a = 10;
	b = 10.0;
	CU_ASSERT( equals_double(&a, &b) );

	a = 10;
	b = 20.0;
	CU_ASSERT( !equals_double(&a, &b) );
}
