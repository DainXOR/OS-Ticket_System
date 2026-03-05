#ifndef RAND_H
#define RAND_H

#include <stdint.h>

void random_init(void);
void random_init_seed(unsigned seed);

uint64_t random_min(void);
uint64_t random_max(void);

uint64_t random_getBetween(uint64_t low, uint64_t high);
uint64_t random_get(void);

#endif
