#include "header.h"

int main(void) {
    int count = 0, tempCount = 0, markDel = 1, markDone = 0;
    tree T;
    isiKontainer huruf;
    char str[102];
    int iter = 0;
    do {
        scanf(" %101[^\n]s", &str);
        // printf("%s\n", str);
        if (strcmp(str, "DONE;") == 0)
            markDone = 1;
        if (markDone == 0){
            modifyData(str);
        }
    }while(markDone != 1);


    // scanf (" %c", &huruf.node); //A
    // makeTree(huruf, &T);
    // count++;
    
    // scanf (" %c", &huruf.node); //B
    // addLeft(huruf, T.root);
    // count++;

    // scanf (" %c", &huruf.node); //C
    // addRight(huruf, T.root);
    // count++;

    // scanf (" %c", &huruf.node); //D
    // addLeft(huruf, T.root->right);
    // count++;

    // scanf (" %c", &huruf.node); //E
    // addRight(huruf, T.root->left);
    // count++;

    // scanf (" %c", &huruf.node); //F
    // addRight(huruf, T.root->right);
    // count++;

    // scanf (" %c", &huruf.node); //G
    // addLeft(huruf, T.root->left->right);
    // count++;

    // scanf (" %c", &huruf.node); //H
    // addRight(huruf, T.root->right->left);
    // count++;

    // scanf (" %c", &huruf.node); //I
    // addRight(huruf, T.root->left->right);
    // count++;

    // scanf (" %c", &huruf.node); //J
    // addRight(huruf, T.root->right->right);
    // count++;

    // scanf (" %c", &huruf.node); //K
    // addLeft(huruf, T.root->right->right);
    // count++;

    // scanf (" %c", &huruf.node); //L
    // addLeft(huruf, T.root->left->right->left);
    // count++;

    // scanf (" %c", &huruf.node); //M
    // addLeft(huruf, T.root->right->left->right);
    // count++;

    // scanf (" %c", &huruf.node); //N
    // addRight(huruf, T.root->right->left->right);
    // count++;
    // tempCount = count;

    // printf("Pre Order:\n");
    // printTreePreOrder(T.root, &count);
    // printf("\n");

    // delLeft(T.root->left->right->left); // L hilang
    // count = tempCount - markDel;
    // markDel++;
    // printf("In Order:\n");
    // printTreeInOrder(T.root, &count);
    // printTreeInOrder(T.root, &count);
    // printf("\n");

    // delRight(T.root->right->right);     // J hilang
    // count = tempCount - markDel;
    // markDel++;
    // printf("Post Order:\n");
    // printTreePostOrder(T.root, &count);
    // printTreePostOrder(T.root);
    // printf("\n");
}