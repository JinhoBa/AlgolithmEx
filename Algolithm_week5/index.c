#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char a, char c, char b);
long count = 0;
void main() {
	int n;
	printf("input the number of disk! \n");
	scanf("%d", &n);
	if (n <= 0)
		printf("");
	else
		hanoi(n, 'A', 'C', 'B');
	printf("Moving count = %ld", count);
}
//  (2**n) - 1 ¹ø
void hanoi(int n, char a, char c, char b) {
	if (n == 1) {
		count++;
		printf("Move disk from %c to %c \n", a, c);
	}
	else {
		hanoi(n - 1, a, b, c);
		hanoi(1, a, c, b);
		hanoi(n - 1, b, c, a);
	}
}