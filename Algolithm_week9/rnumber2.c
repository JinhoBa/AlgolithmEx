#define _CTR_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#define random(n) rand() % n
#define randomize() srand((unsigned int)time(NULL))
#define NUM 20
//0.00 ~ 99.99 ������ �Ǽ����� 20���� �����
// �Ҽ��κ��� �հ� ���� �κ��� ���� ���ϴ� ���α׷�

main()
{
    double rdata[NUM], fsum = 0.0;
    int i, isum = 0, temp;
    randomize();

    for (i = 0; i < NUM; i++) {
        rdata[i] = random(100) + random(100) / 100.0;
        printf("%6.2f  ", rdata[i]);
        if ((i + 1) % 7 == 0) printf("\n");
    }

    for (i = 0; i < NUM; i++) {
        temp = rdata[i];
        isum += temp;
        fsum += (rdata[i] - temp);
    }

    printf("\n\n�����κ��� �� : %d\n", isum);
    printf("\n�Ҽ��κ��� �� : %.3f\n", fsum);
}