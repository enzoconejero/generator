
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
	int* indexes = malloc(lenght_max * sizeof(int));

	for (int i = 0; i < lenght_max; ++i){
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
			getchar();
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
			for (int i = 0; i < length_current; ++i){
				memcpy(word + i * language->alphabet->elements_size,
					language->alphabet->elements,
					language->alphabet->elements_size);
				indexes[i] = 0;
			}
		}

		else{
			printf("Indexes:");
			for (int i = 0; i < lenght_max; ++i){
				printf("\t%d", indexes[i]);		
			}
			printf("\n");

			printf("There are %d to change of %d\n", elements_to_change, length_current);
			//Last element to initial
			// memcpy(word + (length_current - 1) * language->alphabet->elements_size,
			// 	language->alphabet->elements,
			// 	language->alphabet->elements_size);

			//Replace the elements which are equals to last_element
			for (int i = 0; i < elements_to_change; ++i){
				memcpy(word + (length_current - 1 - i) * language->alphabet->elements_size,
					language->alphabet->elements,
					language->alphabet->elements_size);
				indexes[i] = 0;
			}

			//element++
			printf("Change element at index %d by %d\n",
				length_current - elements_to_change - 1,
				*(int8_t*)(language->alphabet->elements + (indexes[length_current - elements_to_change - 1] + 1) * language->alphabet->elements_size));
			memcpy(word + (length_current - elements_to_change - 1) * language->alphabet->elements_size,
				language->alphabet->elements + (indexes[lenght_max - elements_to_change - 1] + 1) * language->alphabet->elements_size,
				language->alphabet->elements_size);

			indexes[lenght_max - elements_to_change - 1] += 1;
		}
	}
}

//	char* last = malloc(alphabet->elements_size);
//	size_t largo = 1;
//	int8_t index0;
//	int8_t index1;
//	while(largo<3){
//
//		for(int a = 0; a < alphabet->elements_count; a++){
//
//			printf("%c ||\t", *(char*)(alphabet->elements + a));
//			memcpy(last + (largo - 1)*alphabet->elements_size,
//					alphabet->elements + a * alphabet->elements_size,
//					alphabet->elements_size);
//
//			//*(last + (largo+1) * alphabet->elements_size) = '\0';
//
//			//printf("%s\n", last);
//
//			for(int c = 0; c < largo; c++){
//				printf("%c ", *(last+c));
//			}
//			printf("\n");
//
//			getchar();
//		}
//
//		//Chequear si es la ultima palabra con ese largo
//		bool ultima = true;
//
//		for(int i = 0; i < largo && ultima; i++){
//			ultima = (*(alphabet->equals))(last + i*alphabet->elements_size, alphabet->last_element);
//		}
//
//		if(ultima){
//			largo ++;
//			printf("Ultima\tLargo %d\n", largo);
//			last = malloc(largo * alphabet->elements_size);
//			for(int j = 0; j < largo; j++){
//				memcpy(last + j*alphabet->elements_size, alphabet->elements, alphabet->elements_size );
//			}
//
//			for(int c = 0; c < largo; c++){
//				printf("%c ", *(last+c));
//			}
//
//		}
//
//		else{
//			printf("Cambia letras\n");
//
//			if(  ){
//
//			}
//
//		}
//	}
