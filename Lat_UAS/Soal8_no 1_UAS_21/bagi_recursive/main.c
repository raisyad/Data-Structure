#include "header.h"

int main()
{
    tree T;

    int akar = 0, bagi = 0, idx = 0;
    scanf("%d %d", &akar, &bagi);
    makeTree(akar, &T);
    devide(T.root, akar, bagi);

    printTreePreOrder(T.root, idx);
    printf("\n");
    return 0;
}