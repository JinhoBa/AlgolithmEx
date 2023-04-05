#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);
void main(int argc, char* argv[]) {

	int a, b, result, answer, correct = 0, i = 0;
	FILE* infile, *out;
	if (argc != 3) {
		printf("�����μ��� �߸� �־����ϴ�.\n");
		exit(1);
	}
	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("�Է������� ���� �����ϴ�.\n");
		exit(1);
	}
	if ((out = fopen(argv[2], "w")) == NULL) {
		printf("��������� ���� �����ϴ�.\n");
		exit(1);
	}
	while (fscanf(infile, "%d %d", &a, &b) != EOF) {
		printf("%d : gcd(%d %d) = ", i + 1, a, b);
		scanf("%d", &answer);
		result = gcd(a, b);
		if (answer != result) {
			printf("Anser : gcd(%d %d) = %d\n", a, b, result);
			fprintf(out, "%d %d\n", a, b);
		}
		
		else {
			printf("correct..");
			correct++;
		}
		i++;
	}
	printf("%d���� �߿� %d ���� ����ϼ̽��ϴ�.\n", i, correct);
}
int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}