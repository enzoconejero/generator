#include "generator.h"

int main(int argc, char** argv){

//	printf("1\n");
	t_language* language = language_create();
//	printf("1\n");
	t_alphabet* alphabet = alphabet_create();
//	printf("1\n");
	alphabet_set_equal(alphabet, &equals_int8);
//	printf("1\n");

	void* elements = malloc(sizeof(int8_t) * 10);
	for (int i = 0;i < 10;
		memcpy(elements + i * sizeof(int8_t), &i, sizeof(int8_t)),
		++i);

	alphabet_set_element(alphabet, elements, 10, sizeof(int8_t));
//	printf("1\n");
	language_set_alphabet(language, alphabet);
	// printf("1\n");
	generate(language);
//
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

	return 0;
}

// char* next_word(char* word){
// 	char* next;
// 	size_t length = strlen(word);

// 	if(is_last_word(word)){
// 		next = (char*) malloc(length + 2); //1 for '\0'
// 		for(int i = 0; i < length + 1; i++){
// 			next[i] = 'a';
// 		}
// 		next[length+1] = '\0';

// 	}
// 	else{
// 		next = strdup(word);
// 		int i = length-1;
// 		while(next[i] == 'z'){
// 			next[i] = 'a';
// 			i--;
// 		}
// 		next[i] += 1;
// 	}

// 	return next;
// }

// bool is_last_word(char* word){
// 	bool is_last = true;
// 	for(int i = 0; i < strlen(word) && is_last; i++){
// 		is_last = is_last && (word[i] == 'z');
// 	}
// 	return is_last;
// }
