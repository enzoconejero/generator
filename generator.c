
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* next_word(char* word);

int main(int argc, char** argv){
	char* string = "a";
	const char* last_word = "zzzz";
	while( strcmp(string, last_word) != 0 ){
//		printf("Word: %s\t", string);
		printf("%s\t", string);
		string = next_word(string);
	}

	printf("%s\t", last_word);
	printf("\n");
	return 0;
}

char* next_word(char* word){
	char* next;

	size_t length = strlen(word);
	bool is_last_word = true;

	for(int i = 0; i < length && is_last_word; i++){
		is_last_word = is_last_word && (word[i] == 'z');
	}

	if(is_last_word){
		next = (char*) malloc(length + 2); //1 for '\0'
		for(int i = 0; i < length + 1; i++){
			next[i] = 'a';
		}
		next[length+1] = '\0';
		return next;
	}
	else{
		next = strdup(word);
		int i = length-1;
		while(next[i] == 'z'){
			next[i] = 'a';
			i--;
		}
		next[i] += 1;
		return next;
	}
}
