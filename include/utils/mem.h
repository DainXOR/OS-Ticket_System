#ifndef MEM_H
#define MEM_H

#include <stdint.h>

void mem_init(void);
void mem_freeAll(void);

void* mem_alloc(uint64_t size);

#endif
