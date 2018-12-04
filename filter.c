
#include "filter.h"

bool filter_default(t_gcb* gcb){
	return true;
}

bool filter_name(t_gcb* gcb){

	void* word = gcb->word;
	int length = gcb->current_length;

	if(length > 2){
		bool is_valid = true;
		char* name = malloc(length + 1);
		memcpy(name, word, length);
		name[length] = '\0';

		// int consonant_count = 0;
		// int vocals_count = 0;
		
		bool any_consonant = false;
		bool any_vocal = false;

		int consonant_consecutive = 0;
		int vocals_consecutive = 0;

		char last_char = name[0];
		int repeats_of_last_char = 0;

		for(int i = 0; i < length; i++){
			char actual = name[i];

			//A consonant and a Vocal
			//No more 2 vocals
			//No more 4 consonants
			//Last 3 chars cant be consonant
			switch(actual){
				
				case 'a': case 'e': case 'i': case 'o': case 'u':
				// vocals_count++;
				any_vocal |= true;
				vocals_consecutive++;
				if(vocals_consecutive == 3){
					return false;
				}
				consonant_consecutive = 0;
				break;

				case 'y':
				consonant_consecutive = 0;
				vocals_consecutive = 0;
				any_consonant |= true;
				any_vocal |= true;
				break;

				default:
				// consonant_count++;
				any_consonant |= true;
				consonant_consecutive++;
				if ( (consonant_consecutive == 5) || ((i == length-1) && (consonant_consecutive == 3))){
					return false;
				}

				vocals_consecutive = 0;
				break;

			}

			//Consecutive repeated chars
			if(last_char == actual){
				repeats_of_last_char++;
				if(repeats_of_last_char == 3){
					return false;
				}
			}
			else{
				last_char = name[i];
				repeats_of_last_char = 0;
			}

		}

		// is_valid = (vocals_count > 0) && (consonant_count > 0);
		is_valid = any_consonant && any_vocal;

		return is_valid;
	}

	return false;
}

bool filter_sudoku(t_gcb* gcb){
	
	bool valid = true;
	bool there_is_num[9];
	int8_t* sudoku = gcb->word;
	int8_t counters[81];
	// printf("Entrado\n");

	if (sudoku[1] == sudoku[2]){
		return false;
	}

	for(int i = 0; i < 9; i++){
		for (int j = 0; j < 81; counters[j] = 0, j++);
		counters[sudoku[i]]++;
	}

	for (int i = 0; i < 81 && valid; valid &= (counters[i] == 9) ,i++);

	if(valid){

		// for (int i = 0; i < 9; there_is_num[i] = false, i++);

		return true;		

	}

	total++;
	if ((total % 1000000) == 0){
		NL;
		total = 0;
		mill++;
		printf("%lu Millon\n", mill);

		for(int i = 0; i < 81; i++){
			printf("%d\t", sudoku[i]);
			if( ((i+1) % 9) == 0 ){
				NL;
			}
		}
	}
	return false;
}






















