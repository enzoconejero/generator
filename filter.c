
#include "filter.h"

bool filter_name(void* word, int length){
	if(length > 3){
		bool is_valid = true;
		char* name = malloc(length + 1);
		memcpy(name, word, length);
		name[length] = '\0';

		int consonant_count = 0;
		int vocals_count = 0;
		
		//bool any_consonant = false;
		//bool any_vocal = false;

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
				
				case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
				vocals_count++;
				// any_vocal |= true;
				vocals_consecutive++;
				if(vocals_consecutive == 3){
					return false;
				}
				consonant_consecutive = 0;
				break;

				default:
				consonant_count++;
				// any_consonant |= true;
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

		is_valid = (vocals_count > 0) && (consonant_count > 0);

		return is_valid;
	}
	return false;
}
