#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int GCD();
void main() {
	int a, b, cond = 1;
	int result;
	while (cond) {
		printf("�ִ������� ���� �μ��� �Է��ϼ��� : ");
		scanf("%d %d", &a, &b);
		result = GCD(a, b);
		printf("%d", result);
		printf("����Ͻðڽ��ϱ�(1/0)");
		scanf("%d", &cond);
	}
}
int GCD(int x, int y) {
	if (y == 0)
		return x;
	else
		return GCD(y, x % y);
	/*int tmp;
	while (y!=0) {
		tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;*/
}