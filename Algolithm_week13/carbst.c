#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* left;
    unsigned carid;
    char cgrade;
    struct node* right;
} CARTYPE;

// 함수와 전역변수 선언
int make_bst(CARTYPE* troot, unsigned id, char grade);
void nonpasscar(CARTYPE* troot);
CARTYPE* treep = NULL;

// main()함수 작성
void main(int count, char*var) {
    FILE* carfile;
    unsigned cid;
    char cgrade;

    if ((carfile = fopen(var[1],"r"))== NULL){
        printf("Cannot open read file ..\n");
        exit(1);
    }
    while ((fscanf(carfile, "%u %c", &cid, &cgrade)) != EOF)
        make_bst(treep, cid, cgrade);

    nonpasscar(treep);
}

int make_bst(CARTYPE* root, unsigned id, char grade) {
    CARTYPE* tptr = root, * before = NULL, * node;
    int first = 0;

    if (root == NULL) first = 1;
    while (tptr) {
        if (id < tptr->carid) {
            before = tptr;
            tptr = tptr->left;
        }
        else if (id > tptr->carid) {
            before = tptr;
            tptr = tptr->right;
        }
        else        // found
            return 0;
    }

    node = (CARTYPE*)malloc(sizeof(CARTYPE));
    node->carid = id;
    node->cgrade = grade;
    node->left = node->right = NULL;
    if (first == 0) {
        if (id < before->carid) before->left = node;
        else   before->right = node;
    }
    else treep = node;
    return 1;
}
void nonpasscar(CARTYPE* root) {
    if (root) {
        nonpasscar(root->left);
        if (root->cgrade != 'A') printf("%d\t", root->carid);
        nonpasscar(root->right);
    }
}