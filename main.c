#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo();
void main() {
	int n, i;
	printf("input n: ");
	scanf("%d", &n);
	for ( i = 0; i <= n; i++){
		printf("%d\t", fibo(n));
	}

}
int fibo(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else
		return fibo(n - 1) + fibo(n - 2);
}
