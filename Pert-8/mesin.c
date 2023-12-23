#include "header.h"

void makeTree(isiKontainer kontainer, tree *T) {
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    //
    baru->kontainer.node = kontainer.node;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

void addRight(isiKontainer kontainer, simpul *node) {
    if (node != NULL) {
        if (node->right == NULL) /*jika sub pohon kanan kosong*/ {
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));
            //
            baru->kontainer.node = kontainer.node;
            baru->right = NULL;
            baru->left = NULL;
            node->right = baru;
            baru = NULL;
        }
        else
            printf("sub pohon kanan telah terisi \n");
    }
}

void addLeft(isiKontainer kontainer, simpul *node) {
    if (node != NULL) {
        if (node->left == NULL) /*jika sub pohon kiri kosong*/ {
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));
            //
            baru->kontainer.node = kontainer.node;
            baru->right = NULL;
            baru->left = NULL;
            node->left = baru;
            baru = NULL;
        }
        else
            printf("sub pohon kiri telah terisi \n");
    }
}

void delAll(simpul *node) {
    if (node != NULL) {
        delAll(node->left);
        delAll(node->right);
        free(node);
    }
}

void delRight(simpul *node) {
    if (node != NULL) {
        if (node->right != NULL) {
            delAll(node->right);
            node->right = NULL;
        }
    }
}

void delLeft(simpul *node) {
    if (node != NULL) {
        if (node->left != NULL) {
            delAll(node->left);
            node->left = NULL;
        }
    }
}

void printTreePreOrder(simpul *node) {
    if (node != NULL) {
        printf(" %c ", node->kontainer.node);
        printTreePreOrder(node->left);
        printTreePreOrder(node->right);
    }
}

void printTreeInOrder(simpul *node) {
    if (node != NULL) {
        printTreeInOrder(node->left);
        printf(" %c ", node->kontainer.node);
        printTreeInOrder(node->right);
    }
}

void printTreePostOrder(simpul *node) {
    if (node != NULL) {
        printTreePostOrder(node->left);
        printTreePostOrder(node->right);
        printf(" %c ", node->kontainer.node);
    }
}

void copyTree(simpul *node1, simpul **node2) {
    if (node1 != NULL) {
        (*node2) = (simpul *)malloc(sizeof(simpul));
        (*node2)->kontainer.node = node1->kontainer.node;
        if (node1->left != NULL)
            copyTree(node1->left, &(*node2)->left);
        if (node1->right != NULL)
            copyTree(node1->right, &(*node2)->right);
    }
}

int isEqual(simpul *node1, simpul *node2) {
    int hasil = 1;
    if ((node1 != NULL) && (node2 != NULL)) {/* jika simpul pohon 1 dan pohon 2 sama sama tidak NULL */
        if (node1->kontainer.node != node2->kontainer.node) /* jika isi kontainer simpul pohon 1 dan pohon 2 tidak sama */
            hasil = 0;
        else /* jika isi kontainer simpul pohon 1 dan simpul pohon 2 sama, maka telusuri simpul selanjutnya */
        {
            isEqual(node1->left, node2->left);
            isEqual(node1->right, node2->right);
        }
    }
    else {
        if ((node1 != NULL) || (node2 != NULL)) /* jika salah satu simpul ada yang NULL */
            hasil = 0;
    }
    return hasil;
}