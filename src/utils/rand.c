#include "utils/rand.h"

#include <stdint.h>
#include <stdlib.h>
#include <time.h>



void random_init(void){
	srand((unsigned)time(NULL));
}
void random_init_seed(unsigned seed){
	srand(seed);
}

uint64_t random_min(void){
	return 0;
}
uint64_t random_max(void){
	return INT64_MAX;
}
uint64_t random_getBetween(uint64_t low, uint64_t high){
	uint64_t randomValue = 0;
	uint64_t range = high - low + 1;

    for (int i = 0; i < 5; i++) {
        randomValue = (randomValue << 15) | (rand() & 0x7FFF);
    }

    return low + (randomValue % range);
}
uint64_t random_get(void){
	return random_getBetween(random_min(), random_max());
}
