
#include "language.h"

//Tested
t_language* language_create(){
	t_language* language = (t_language*) malloc(sizeof(t_language));
	language->alphabet = NULL;
	language->print = NULL;
	return language;
}

//Tested
void language_destroy(t_language* language){
	free(language->alphabet);
	free(language);
}

//Tested
void language_set_alphabet(t_language* language, t_alphabet* alphabet){
	if(language->alphabet != NULL){
		free(language->alphabet);
	}
	language->alphabet = alphabet;
}

void language_set_print(t_language* language, void (*print)(void* a)){
	if(language->print != NULL){
		free(language->print);
	}
	language->print = print;
}

void generate(t_language* language){
	int lenght_max = 4; //Hardcoded;

	//Inicializations
	void* elements = language->alphabet->elements;
	void* last_element = language->alphabet->last_element;
	size_t size = language->alphabet->elements_size;
	size_t count = language->alphabet->elements_count;

	bool equals(void* a,void* b){
		(*(language->alphabet->equals))(a,b);
	};

	void print(void* a){
		(*(language->print)) (a);
	}

	int length_current = 1;
	void* word = malloc(size);
	int* indexes = malloc(length_current * sizeof(int));
	for (int i = 0; i < length_current; indexes[i] = 0, ++i);
	
	while(length_current < lenght_max){

		// printf("Lenght: %d\n", length_current); //debug
		for(int i = 0; i < count; i++){
			memcpy(word + (length_current-1) * size,
					elements + i * size,
					size);

			for (int i = 0; i < length_current; ++i){
				print(word + i);
				printf("\t");
			}
			printf("\n");
		}
		
		//Check if is the max word
		bool is_element_to_change = true;
		int elements_to_change = 0;

		for (int i = 0; i < length_current && is_element_to_change; ++i){

			is_element_to_change = equals(word + (length_current - 1 - i ) * size, last_element);

			if(is_element_to_change){
				elements_to_change++;
			}
		}

		// printf("%d elements to change of %d\n", elements_to_change, length_current);

		if (elements_to_change == length_current){
			printf("Is the last word with %d lenght\n", length_current);
			length_current++;

			free(word);
			free(indexes);

			word = malloc(length_current);
			indexes = malloc(length_current * sizeof(int));

			for (int i = 0; i < length_current; ++i){
				memcpy(word + i * size,
					elements,
					size);

				indexes[i] = 0;
			}
		}

		else{

			//debug
			printf("Indexes:");
			for (int i = 0; i < length_current; ++i){
				printf("\t%d", indexes[i]);		
			}
			printf("\n");
			// debug

			// printf("There are %d to change of %d\n", elements_to_change, length_current);//debug

			//Replace the elements which are equals to last_element
			for (int i = 0; i < elements_to_change; ++i){
				memcpy(word + (length_current - 1 - i) * size,
					elements,
					size);
				indexes[length_current - 1 - i] = 0;
			}

			//element++
			printf("Change element at index %d by %d\n",
				length_current - elements_to_change - 1,
				*(int8_t*)(elements+ (indexes[length_current - elements_to_change - 1] + 1) * size));

			memcpy(word + (length_current - elements_to_change - 1) * size,
				elements+ (indexes[length_current - elements_to_change - 1] + 1) * size,
				size);

			indexes[length_current - elements_to_change - 1] += 1;
			getchar();
		}
	}
}
