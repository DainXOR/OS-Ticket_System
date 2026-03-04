#include "utils/rand.h"

#include <stdlib.h>
#include <time.h>

void random_init(void){
	srand((unsigned)time(NULL));
}

void random_init_seed(unsigned seed){
	srand(seed);
}

int random_get(void){
	return rand();
}
