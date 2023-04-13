#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15
void main() {
	int n, i, j, sum = 0;
	int count, row, col;
	int table[MAX_SIZE][MAX_SIZE];

	printf("Enter Number : ");
	scanf("%d", &n);

	if ((n < 1) || n > MAX_SIZE) {
		printf("Error! size is out of range");
		exit(0);
	}
	if (n % 2 == 0) {
		printf("Error!!");
	}
	// �迭 0���� ä���
	for ( i = 0; i < n; i++){
		for ( j = 0; j < n; j++)
			table[i][j] = 0;
	}
	//������ �� �Է�
	i = 0;
	j = (n - 1) / 2;
	table[i][j] = 1;
	for ( count = 2; count < n*n; count++){ 
		row = (i - 1 < 0) ? (n - 1) : (i - 1);
		col = (j - 1 < 0) ? (n - 1) : (j - 1);
		if (table[row][col])
			i++;
		else {
			i = row;
			j = col;
		}
		table[i][j] = count;
	}
	// ������ ���
	for ( i = 0; i < n; i++){
		for ( j = 0; j < n; j++){
			printf("%d \t", table[i][j]);
		}
		printf("\n");
	}
	// ������ �� ���
	for ( j = 0; j < n; j++){
		sum = sum + table[0][j];
	}
	printf("sum : %d", sum);

}