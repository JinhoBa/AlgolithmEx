#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 50
#define random(n) rand() % n

void insertion(double a[], int n);
main()
{
	double rdata[NUM];
	int i;

	srand((unsigned int)time(NULL));

	for (i = 0; i < NUM; i++) {
		rdata[i] = random(100) + random(100) / 100.0;
		printf("%6.2f  ", rdata[i]);
		if ((i + 1) % 7 == 0) printf("\n");
	}

	insertion(rdata, NUM);

	printf("\n\n정렬된 데이터~~~\n");
	for (i = 0; i < NUM; i++) {
		printf("%6.2f  ", rdata[i]);
		if ((i + 1) % 7 == 0) printf("\n");
	}
}
void insertion(double a[], int n) {
	int i, j, key;
	for ( i = 0; i < n-1; i++){
		key = a[i];
		j = i - 1;
		while (a[j] > key && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}