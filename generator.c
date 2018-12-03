
#include "generator.h"

// typedef struct{
// 	//General stuff
// 	void* word;
// 	int* indexes;
// 	int current_length;
// 	//Language stuff
// 	void* elements;
// 	void* last_element;
// 	size_t element_size;
// 	size_t element_count;
// 	bool (*equals)(void* a, void*b);
// }t_gcb;

// typedef struct{
// 	t_language* language;
// 	t_gcb* gcb;
// 	bool (*stop_condition)(t_gcb*);
// 	bool (*filter)(t_gcb*);
// 	void (*printer)(t_gcb*);
// 	void (*persister)(t_gcb*);
// }t_generator;

t_gcb* gcb_create(t_language* language){
	t_gcb* gcb = malloc(sizeof(t_gcb));

	gcb->elements = language->elements;
	gcb->last_element = language->last_element;
	gcb->element_size = language->elements_size;
	gcb->element_count = language->elements_count;
	gcb->equals = language->equals;

	gcb->word = NULL;
	gcb->indexes = NULL;
	gcb->current_length = 0;

	return gcb;
}

t_generator* generator_create(t_language* language){
	t_generator* generator = malloc(sizeof(t_generator));

	generator->language = language;
	generator->printer = (void (*)(t_gcb*)) language->print;
	generator->filter = language->filter;
	generator->gcb = gcb_create(language);

	return generator;
}

void generator_set_filter(t_generator* generator, bool (*filter)(t_gcb*) ){
	generator->filter = filter;
}

void generator_set_stop_condition(t_generator* generator, bool (*stop_condition)(t_gcb*) ){
	generator->stop_condition = stop_condition;
}

void generator_set_persister(t_generator* generator, void (*persister)(t_gcb*) ){
	generator->persister = persister;
}

void generate(t_generator* generator){
	t_gcb* gcb = generator->gcb;

	gcb->word = malloc(gcb->element_size * gcb->current_length);
	gcb->indexes = malloc(gcb->current_length * gcb->element_size);
	for (int i = 0; i < gcb->current_length; 
		gcb->indexes[i] = 0, 
		memcpy(gcb->word + i * gcb->element_size, gcb->elements, gcb->element_size),
		++i);
	// int length_max = length;
	// int length_initial = 3;

	//Inicializations
	// void* elements = language->elements;
	// void* last_element = language->last_element;
	// size_t size = language->elements_size;
	// size_t count = language->elements_count;


	// bool equals(void* a,void* b){
	// 	(*(language->equals))(a,b);
	// };

	// void print(void* a){
	// 	(*(language->print)) (a);
	// }

	// bool filter(void* a, int length_of_a){
	// 	(*(language->filter)) (a, length_of_a);
	// }

	// int current_length = length_initial;
	// void* word = malloc(size * current_length);
	// int* indexes = malloc(current_length * sizeof(int));

	// for (int i = 0; i < current_length; indexes[i] = 0, memcpy(word + i * size,	elements, size),++i);
	
	// while(current_length <= length_max){
	log_screen("1-Inicializa");
	while( (*(generator->stop_condition)) (gcb) ){
		log_screen("2-Entra ciclo");
		// printf("length: %d\n", current_length); //debug
		for(int i = 0; i < gcb->element_count; i++){
			memcpy(gcb->word + (gcb->current_length-1) * gcb->element_size,
					gcb->elements + i*gcb->element_size,
					gcb->element_size);
			
			log_screen("3-Genera palabra");
			/*Filter*/
			if( (*(generator->filter)) (gcb)){
			// if(!filter(word, current_length)){
				//SHOW CURRENT WORD
				// for (int i = 0; i < current_length; ++i){
				// 	print(word + i);
				// }
				log_screen("4-Pasa filtro");
				if(generator->printer != NULL){
					(*(generator->printer)) (gcb);
					log_screen("3.1-La muestra");
				}
				
				if(generator->persister != NULL){
					(*(generator->persister))(gcb);
					log_screen("3.2-La guarda");
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

		log_screen("4-Cambia las otras letras");

		if (elements_to_change == gcb->current_length){
			log_screen("4.1-Aumenta el largo");
			gcb->current_length++;

			// printf("4.1,1\n");

			// free( gcb->word );  //TODO: 

			// printf("4.1,2\n");

			free(gcb->indexes);

			// printf("4.1,3\n");

			gcb->word = malloc(gcb->current_length);

			// printf("4.1,3\n");

			gcb->indexes = malloc(gcb->current_length * sizeof(int));

			// printf("4.1,2\n");

			for (int i = 0; i < gcb->current_length; ++i){
				memcpy(gcb->word + i * gcb->element_size,
					gcb->elements,
					gcb->element_size);

				gcb->indexes[i] = 0;
			}

			// printf("4.1,3\n");

		}

		else{
			//Replace the elements which are equals to last_element
			log_screen("4.2-No aumenta el largo");
			for (int i = 0; i < elements_to_change; ++i){
				memcpy(gcb->word + (gcb->current_length - 1 - i) * gcb->element_size,
					gcb->elements,
					gcb->element_size);
				gcb->indexes[gcb->current_length - 1 - i] = 0;
			}

			//element++
			// log_screen("Change element at index %d by %d\n",
			// 	current_length - elements_to_change - 1,
			// 	*(int8_t*)(elements+ (indexes[current_length - elements_to_change - 1] + 1) * size));

			memcpy(gcb->word + (gcb->current_length - elements_to_change - 1) * gcb->element_size,
				gcb->elements+ (gcb->indexes[gcb->current_length - elements_to_change - 1] + 1) * gcb->element_size,
				gcb->element_size);

			gcb->indexes[gcb->current_length - elements_to_change - 1] += 1;
		}
	}	
}
