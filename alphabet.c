
#include "alphabet.h"

//Tested
t_alphabet* alphabet_create(){
	t_alphabet* alphabet = (t_alphabet*) malloc(sizeof(t_alphabet));
	alphabet->elements = NULL;
	alphabet->elements_count = 0;
	alphabet->elements_size = 0;
	alphabet->last_element = NULL;
	alphabet->equals = NULL;
	return alphabet;
}

//Tested
void alphabet_destroy(t_alphabet* alphabet){
	if(alphabet != NULL){
		free(alphabet->elements);
		free(alphabet);
	}
	alphabet = NULL;
}

//Tested
void alphabet_set_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size){
	printf("0\n");
	if(alphabet->elements != NULL){
		free(alphabet->elements);
	}

	void* filtred_elements = malloc(elements_count * elements_size);
	void* elemA = malloc(elements_size);
	void* elemB = malloc(elements_size);

	bool to_add = true;
	size_t filtred_elements_count = 0;
	for(int i = 0; i < elements_count; i++){
		memcpy(elemA, elements + (i*elements_size), elements_size );
		for(int j = 0; j < filtred_elements_count && to_add; j++){
			memcpy(elemB, filtred_elements + (j * elements_size), elements_size);
			if ((*(alphabet->equals)) (elemA ,elemB)){
				to_add = false;
			}
		}
		if(to_add){
			memcpy(filtred_elements + filtred_elements_count * elements_size, elemA , elements_size);
			filtred_elements_count++;
		}
	}

	printf("\n%d Agregados\n", filtred_elements_count);
	filtred_elements = realloc(filtred_elements, elements_size * elements_count);

	alphabet->elements = filtred_elements;
	alphabet->elements_count = filtred_elements_count;
	alphabet->elements_size = elements_size;
	alphabet->last_element = malloc(elements_size);
	memcpy(alphabet->last_element,
			elements + elements_size*(elements_count-1),
			elements_size);
}

//TODO test
void alphabet_add_element(t_alphabet* alphabet, void* elements, size_t elements_count, size_t elements_size){
	//When there is not any element
	if(alphabet->elements_count == 0){
		printf("Sin elementos\n");
		alphabet->elements = elements;
		alphabet->elements_count = elements_count;
		alphabet->elements_size = elements_size;
		alphabet->last_element = malloc(elements_size);
		memcpy(alphabet->last_element,
				elements + elements_size*(elements_count-1),
				elements_size);
	}
	//When there is any element
	else if(alphabet->elements_size == elements_size ){
		printf("Con elementos\n");
		//Filter repeated elements
		void* unrepeated_elements = malloc(elements_count * elements_size);
		size_t bytes_copied = 0;
		size_t new_elements = 0;
		printf("For\n");
		for(int i = 0; i < elements_count; i++){
			bool is_repeated = false;
			void* new = malloc(elements_size);
			void* old = malloc(elements_size);
			printf("1\n");
			memcpy(new, elements, elements_size);
			printf("2\n");
			for(int j = 0; i < alphabet->elements_count || is_repeated ; i++){
				memcpy(old, alphabet->elements + elements_size*i, elements_size);
				printf("3\n");
				if( (*(alphabet->equals))(new,old) ){
					printf("4\n");
					memcpy(unrepeated_elements, new, elements_size);
					bytes_copied += elements_size;
					new_elements++;
					is_repeated = true;
					printf("6\n");
				}
			}
		}
		printf("Elementos filtrados\n");
		//resize new elements array
		unrepeated_elements = realloc(unrepeated_elements, bytes_copied);

		size_t old_size = alphabet->elements_count * alphabet->elements_size;
		//size_t new_size = elements_count * elements_size;
		alphabet->elements = realloc(alphabet->elements, old_size + bytes_copied );
		memcpy(alphabet->elements + old_size, elements, bytes_copied);
		alphabet->elements_count += new_elements;
		free(alphabet->last_element);
		alphabet->last_element = malloc(elements_size);
		memcpy(alphabet->last_element,
				elements + elements_size*(elements_count-1),
				elements_size);
	}

	else{
		printf("The size of elements <%d> should be equals to the size of existing elements <%d>\n", elements_count, alphabet->elements_size);
	}
}

//TODO TEST
void alphabet_set_equal(t_alphabet* alphabet, bool(*equal)(void*,void*)){
	alphabet->equals = equal;
}

bool equals_char(void* c1, void* c2){
	return *((char*) c1) == *((char*) c2);
}

//TODO TEST
bool equals_words_char(const char* c1,const char* c2){
	return strcmp(c1, c2) == 0;
}

//Tested
char* element_get_upCase(){
	char* elements = malloc(LETTERS_COUNT);
	for(int i = 0; i < LETTERS_COUNT; elements[i] = 'A' + i, i++);
	return elements;
}

//Tested
char* element_get_lowCase(){
	char* elements = malloc(LETTERS_COUNT);
	for(int i = 0; i < LETTERS_COUNT; elements[i] = 'a' + i, i++);
	return elements;
}

//Tested
char* element_get_numbers(){
	char* elements = malloc(10);
	for(int i = 0; i < 10; elements[i] = '0' + i, i++);
	return elements;
}
