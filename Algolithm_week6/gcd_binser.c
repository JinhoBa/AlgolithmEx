#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define INUM 100
int bsearch_stock(long s[][2], long key, int left, int right);
long stocksum(long s[][2], int n);

main(int argc, char* argv[])
{
    FILE* stockdb;
    long stock[INUM][2], item_code;
    int k = 0, s;

    if ((stockdb = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open read file....\n");
        exit(1);
    }
    while ((fscanf(stockdb, "%ld %ld", &stock[k][0], &stock[k][1])) != EOF) {
        printf("%ld\n", stock[k][0]); k++;
    }
    printf("�˻��� item number �Է� : ");
    scanf("%ld", &item_code);
    s = bsearch_stock(stock, item_code, 0, k - 1);
    if (s == -1) printf("���ǰ�� �����ϴ�\n");
    else printf("%ld�� ����� = %u\n", stock[s][0], stock[s][1]);

    printf("��ü ���ǰ�� ���� �� = %ld\n", stocksum(stock,k));
}
int bsearch_stock(long s[][2], long key, int left, int right) {
    int mid;
    if (left <= right) {
        mid = (left + right) / 2;
        if (key > s[mid][2]) return bsearch_stock(s, key, mid + 1, right);
        else if (key < s[mid][2]) return bsearch_stock(s, key, left, mid - 1);
        else return mid;
    }
    return -1;
}
long stocksum(long s[][2], int n) {
    long sum = 0;
    int i;
    for ( i = 0; i < n; i++){
        sum += s[i][1];
    }
    return sum;
}