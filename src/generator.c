
#include "generator.h"

t_gcb* gcb_create(t_language* language){
	t_gcb* gcb = malloc(sizeof(t_gcb));

	gcb->elements = language->elements;
	gcb->last_element = language->last_element;
	gcb->element_size = language->elements_size;
	gcb->element_count = language->elements_count;
	gcb->equals = language->equals;

	gcb->word = malloc(language->elements_size);
	memcpy(gcb->word, language->elements, language->elements_size);
	gcb->indexes = malloc(sizeof(int));
	gcb->indexes[0] = 0;
	return gcb;
}

void gcb_free(t_gcb* gcb){
	free(gcb->indexes);
	free(gcb);
}

t_generator* generator_create(t_language* language){
	t_generator* generator = malloc(sizeof(t_generator));

	generator->language = language;
	generator->printer = (void (*)(t_gcb*)) language->print;
	generator->filter = language->filter;
	generator->gcb = gcb_create(language);
	generator->stop_condition = &stop_condition_default;
	return generator;
}

void generator_set_filter(t_generator* generator, bool (*filter)(t_gcb*) ){
	generator->filter = filter;
}

void generator_set_stop_condition(t_generator* generator, bool (*stop_condition)(t_gcb*) ){
	generator->stop_condition = stop_condition;
}

bool stop_condition_default(t_gcb* gcb){
	return false;
}

void generator_set_persister(t_generator* generator, void (*persister)(t_gcb*) ){
	generator->persister = persister;
}

void generator_set_initial_word(t_generator* generator, void* word, size_t length){

	if(language_is_valid_word(generator->language, word, length)){
		int* indexes = malloc(sizeof(int) * length);
		
		for(int i = 0; i < length; i++){
			indexes[i] = language_indexOf(generator->language, word + i * generator->language->elements_size);
		}

		free(generator->gcb->indexes);
		free(generator->gcb->word);

		generator->gcb->indexes = indexes;
		generator->gcb->current_length = length;
		generator->gcb->word = malloc(length * generator->language->elements_size);
		memcpy(generator->gcb->word, word, length * generator->language->elements_size);
	}

	//ERROR

}

void generator_set_initial_length(t_generator* generator, size_t length){
	free(generator->gcb->indexes);
	free(generator->gcb->word);

	void *word = malloc( length * generator->gcb->element_size );
	int* indexes = malloc(sizeof(int) * length);
	for(int i = 0; i < length;  i++){
		memcpy(word + i * generator->gcb->element_size, generator->gcb->elements, generator->gcb->element_size);
		indexes[i] = 0;
	}
	
	generator->gcb->current_length = length;
	generator->gcb->word = word;
	generator->gcb->indexes = indexes;
}

void generate(t_generator* generator){
	t_gcb* gcb = generator->gcb;

	while( ! ((*(generator->stop_condition)) (gcb)) ){

		for(int i = 0; i < gcb->element_count - gcb->indexes[gcb->current_length-1]; i++){

			memcpy(gcb->word + (gcb->current_length-1) * gcb->element_size,
					gcb->elements + (i + gcb->indexes[gcb->current_length-1]) * gcb->element_size,
					gcb->element_size);
			
			/*Filter*/
			if( (*(generator->filter)) (gcb)){
				/*Printer*/
				if(generator->printer != NULL){
					(*(generator->printer)) (gcb);
				}
				
				/*Persister*/
				if(generator->persister != NULL){
					(*(generator->persister))(gcb);
				}
			}
		}
		
		//Check if is the max word
		bool is_element_to_change = true;
		int elements_to_change = 0;

		for (int i = 0; i < gcb->current_length && is_element_to_change; ++i){

			is_element_to_change = (*(gcb->equals)) (gcb->word + (gcb->current_length - 1 - i ) * gcb->element_size, gcb->last_element);

			if(is_element_to_change){
				elements_to_change++;
			}
		}


		if (elements_to_change == gcb->current_length){
			//Length++
			gcb->current_length++;

			// free( gcb->word );  //TODO: 
			free(gcb->indexes);

			gcb->word = malloc(gcb->current_length);
			gcb->indexes = malloc(gcb->current_length * sizeof(int));

			for (int i = 0; i < gcb->current_length; ++i){
				memcpy(gcb->word + i * gcb->element_size,
					gcb->elements,
					gcb->element_size);

				gcb->indexes[i] = 0;
			}
		}

		else{
			//Replace the elements which are equals to last_element
			for (int i = 0; i < elements_to_change; ++i){
				memcpy(gcb->word + (gcb->current_length - 1 - i) * gcb->element_size,
					gcb->elements,
					gcb->element_size);
				gcb->indexes[gcb->current_length - 1 - i] = 0;
			}

			memcpy(gcb->word + (gcb->current_length - elements_to_change - 1) * gcb->element_size,
				gcb->elements+ (gcb->indexes[gcb->current_length - elements_to_change - 1] + 1) * gcb->element_size,
				gcb->element_size);

			gcb->indexes[gcb->current_length - elements_to_change - 1] += 1;
		}
	}	
}
