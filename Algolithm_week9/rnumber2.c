#define _CTR_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#define random(n) rand() % n
#define randomize() srand((unsigned int)time(NULL))
#define NUM 20
//0.00 ~ 99.99 사이의 실수난수 20개를 만들어
// 소수부분의 합과 정수 부분의 합을 구하는 프로그램

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

    printf("\n\n정수부분의 합 : %d\n", isum);
    printf("\n소수부분의 합 : %.3f\n", fsum);
}