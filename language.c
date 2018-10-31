
#include "language.h"

//Tested
t_language* language_create(){
	t_language* language = (t_language*) malloc(sizeof(t_language));
	language->alphabet = NULL;
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

void generate(t_language* language){
	int lenght_max = 5; //Hardcoded;
	int length_current = 1;

	void* word = malloc(language->alphabet->elements_size);

	int* indexes = malloc(length_current * sizeof(int));

	for (int i = 0; i < length_current; ++i){
		indexes[i] = 0;
	}
	
	while(length_current < lenght_max){
		printf("Lenght: %d\n", length_current);
		for(int i = 0; i < language->alphabet->elements_count; i++){

			memcpy(word + (length_current-1) * language->alphabet->elements_size,
					language->alphabet->elements + i * language->alphabet->elements_size,
					language->alphabet->elements_size);

			for (int i = 0; i < length_current; ++i){
				printf("%d\t", *(int8_t*)(word + i * language->alphabet->elements_size) );
			}
			// printf("\t");
			getchar();//Only for tests
		}
		
		printf("\n");

		//Check if is the max word
		bool is_element_to_change = true;
		int elements_to_change = 0;

		for (int i = 0; i < length_current && is_element_to_change; ++i){
			is_element_to_change = (*(language->alphabet->equals)) 
				(word + (length_current - 1 - i ) * language->alphabet->elements_size,
				language->alphabet->last_element);

			if(is_element_to_change){
				elements_to_change++;
			}
		}

		printf("%d elements to change of %d\n", elements_to_change, length_current);

		if (elements_to_change == length_current){
			printf("Is the last word whith %d lenght\n", length_current);
			length_current++;
			word = malloc(length_current);

			indexes = malloc(length_current * sizeof(int));

			for (int i = 0; i < length_current; ++i){
				memcpy(word + i * language->alphabet->elements_size,
					language->alphabet->elements,
					language->alphabet->elements_size);

				indexes[i] = 0;
			}
		}

		else{
			
			printf("Indexes:");
			for (int i = 0; i < length_current; ++i){
				printf("\t%d", indexes[i]);		
			}

			printf("\n");
			printf("There are %d to change of %d\n", elements_to_change, length_current);

			//Replace the elements which are equals to last_element
			for (int i = 0; i < elements_to_change; ++i){
				memcpy(word + (length_current - 1 - i) * language->alphabet->elements_size,
					language->alphabet->elements,
					language->alphabet->elements_size);
				indexes[length_current - 1 - i] = 0;
			}

			//element++
			printf("Change element at index %d by %d\n",
				length_current - elements_to_change - 1,
				*(int8_t*)(language->alphabet->elements + (indexes[length_current - elements_to_change - 1] + 1) * language->alphabet->elements_size));

			memcpy(word + (length_current - elements_to_change - 1) * language->alphabet->elements_size,
				language->alphabet->elements + (indexes[length_current - elements_to_change - 1] + 1) * language->alphabet->elements_size,
				language->alphabet->elements_size);

			indexes[length_current - elements_to_change - 1] += 1;
		}
	}
}
