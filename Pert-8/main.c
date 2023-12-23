#include "header.h"

int main(void) {
    tree T;
    isiKontainer huruf;
    huruf.node = 'A';
    makeTree(huruf, &T);
    //
    huruf.node = 'B';
    addLeft(huruf, T.root);

    huruf.node = 'C';
    addRight(huruf, T.root);

    huruf.node = 'D';
    addLeft(huruf, T.root->left);

    huruf.node = 'E';
    addRight(huruf, T.root->left);

    huruf.node = 'F';
    addRight(huruf, T.root->right);

    // A
    // B (Left)
    // C F(right) (Right)

    printf("=================\n");
    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    printf("inOrder\n");
    printTreeInOrder(T.root);
    printf("\n=================\n");
    printf("postOrder\n");
    printTreePostOrder(T.root);
    printf("\n=================\n");
    // //
    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1) {
        printf("pohon sama\n");
    }
    else {
        printf("pohon tidak sama\n");
    }
    delRight(T.root->left);
    delLeft(T.root->left);
    printf("=================\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
}