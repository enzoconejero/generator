#include "generator.h"

int main(int argc, char** argv){
	char* string = strdup(INITAL_WORD);
	const char* last_word = "zzz";

	t_language* names = language_create();
	alphabet_set_element(names->alphabet, element_get_upCase(), LETTERS_COUNT, sizeof(char));

//	char* previus;
//	for(char* string = strdup(INITAL_WORD);
//			strcmp(string,last_word) != 0;
//			printf("%s\t", string), previus = string, string = next_word(string), free(previus));
//
//	printf("%s\t", last_word);
//	printf("\n");

	return 0;
}

char* next_word(char* word){
	char* next;
	size_t length = strlen(word);

	if(is_last_word(word)){
		next = (char*) malloc(length + 2); //1 for '\0'
		for(int i = 0; i < length + 1; i++){
			next[i] = 'a';
		}
		next[length+1] = '\0';

	}
	else{
		next = strdup(word);
		int i = length-1;
		while(next[i] == 'z'){
			next[i] = 'a';
			i--;
		}
		next[i] += 1;
	}

	return next;
}

bool is_last_word(char* word){
	bool is_last = true;
	for(int i = 0; i < strlen(word) && is_last; i++){
		is_last = is_last && (word[i] == 'z');
	}
	return is_last;
}
