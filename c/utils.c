#include "utils.h"
#include <stdint.h>

/*
	Array-based queue implementation
*/
int q_empty(Queue* q){
	return q->size==0;
}

void q_enqueue(Queue* q, uint64_t e){
	q->array[q->tail]=e;
	q->tail=(q->tail+1)%q->maxsize;
	q->size++;
}

uint64_t q_serve(Queue* q){
	uint64_t e=q->array[q->head];
	q->head=(q->head+1)%q->maxsize;
	q->size--;
	return e;
}


/*
	Recursive implementation of Euclidean algorithm
*/
uint64_t gcd(uint64_t a, uint64_t b){
	return !b ? a : gcd(b, a%b);
}


/*
	Safe unsigned 64-bit difference
*/
uint64_t uint64_diff(uint64_t a, uint64_t b){
	if (a>b)
		return a-b;
	return b-a;
}


/*
	Fast modular exponentiation
		Works by representing exponent d as binary, and multiplying the result by a^(2^k) where k is the number of times d has been right-shifted
*/
uint64_t modpow(uint64_t a, uint64_t d, uint64_t n){
	uint64_t result = 1;
	while (d) {
		if (d & 1)
			result = (result * a) % n;
		d >>= 1;
		a = (a * a) % n;
	}
	return result;
}


/*
	Pollard's rho algorithm pseudorandom generator
		Subject to overflow, even when working modulo n. 0<=x<n, so x*x could easily be >n=64-bit capacity
*/
uint64_t f(uint64_t x, int c, uint64_t n){
	return (x*x +c) % n;
}


/*
	Bases needed for deterministic primality test for integers < 2^64 == 64-bit
*/
int miller_rabin_bases[]={2,3,5,7,11,13,17,19,23,29,31,37};

int equal_to_miller_rabin_bases(uint64_t n){
	int i;
	for (i=0; i<12;i++){
		if ((int)n==miller_rabin_bases[i]) return 1;
	}
	return 0;
}