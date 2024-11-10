#ifndef csc281_project_utils
#define csc281_project_utils
#include <stdint.h>

typedef struct {
	int head, tail;
	int size, maxsize;
	uint64_t* array;
} Queue;
int q_empty(Queue* q);
void q_enqueue(Queue* q, uint64_t e);
uint64_t q_serve(Queue* q);

uint64_t gcd(uint64_t a, uint64_t b);

uint64_t uint64_diff(uint64_t a, uint64_t b);

uint64_t modpow(uint64_t a, uint64_t d, uint64_t n);

uint64_t f(uint64_t x, int c, uint64_t n); 

extern int miller_rabin_bases[];
int equal_to_miller_rabin_bases(uint64_t n);

#endif