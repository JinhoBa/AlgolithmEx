#define _CTR_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#define random(n) rand() % n 
#define randomize() srand((unsigned int)time(NULL))
#define DNUM 50

void main() {
	int data[DNUM], i, psum = 0, nsum = 0;
	for ( i = 0; i < DNUM; i++){
		data[i] = -100 + random(201);
	}

	for ( i = 0; i < DNUM; i++)	{
		printf("%5d ", data[i]);
		if ((i + 1) % 10 == 0) printf("\n");
		if (data[i] > 0) psum = psum + data[i];
		else nsum = nsum + data[i];
	}
	printf("\nSum of positive number : %d\n", psum);
	printf("Sum of negative number : %d\n", nsum);
}