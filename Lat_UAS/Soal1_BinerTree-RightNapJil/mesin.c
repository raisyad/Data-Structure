#include "header.h"

void makeTree(isiKontainer kontainer, tree *T) {
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    //
    baru->kontainer.child = kontainer.child;
    baru->right = NULL;
    baru->left = NULL;
    baru->parent = NULL;
    (*T).root = baru;
    baru = NULL;
}

int countElement(int a, simpul *root){
    if(root != NULL){
        a++;
        a=countElement(a, root->left);
        a=countElement(a, root->right);
        return a;
    }
}

void addRight(isiKontainer kontainer, simpul *node) {
    if (node != NULL) {
        if (node->right == NULL) /*jika sub pohon kanan kosong*/ {
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));
            //
            baru->kontainer.child = kontainer.child;
            baru->right = NULL;
            baru->left = NULL;
            node->right = baru;
            baru->parent = node;
            baru = NULL;
        }
    }
}

void addLeft(isiKontainer kontainer, simpul *node) {
    if (node != NULL) {
        if (node->left == NULL) /*jika sub pohon kiri kosong*/ {
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));
            //
            baru->kontainer.child = kontainer.child;
            baru->right = NULL;
            baru->left = NULL;
            node->left = baru;
            baru->parent = node;
            baru = NULL;
        }
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

void printTreePreOrder(simpul *node, int *sumNode) {
    int mark = 0;
    if (node != NULL) {
        printf("%d\n", node->kontainer.child);
        if (node->kontainer.child % 2 == 0) {
            node->kontainer.genap += node->kontainer.genap;
        }else {
            node->kontainer.ganjil += node->kontainer.ganjil;
        }
        // if (node->kontainer.child && *sumNode != 1)
        //     printf(" - ");
        *sumNode = *sumNode - 1;
        printTreePreOrder(node->left, sumNode);
        printTreePreOrder(node->right, sumNode);
    }
}

int Process(simpul *node, int *ganjil, int *genap) {
    if (node != NULL) {
        if (node->kontainer.child % 2 == 0) {
            *ganjil = *ganjil + node->kontainer.child;
        }else {
            *genap = *genap + node->kontainer.child;
        }
        Process(node->left, ganjil, genap);
        Process(node->right, ganjil, genap);
    }
}

void printTreeInOrder(simpul *node, int *sumNode) {
    if (node != NULL) {
        printTreeInOrder(node->left, sumNode);
        printf("%c", node->kontainer.child);
        if (node->kontainer.child && *sumNode != 1)
            printf(" - ");
        
        *sumNode = *sumNode - 1;
        printTreeInOrder(node->right, sumNode);
    }
}

void printTreePostOrder(simpul *node, int *sumNode) {
    if (node != NULL) {
        printTreePostOrder(node->left, sumNode);
        printTreePostOrder(node->right, sumNode);
        printf("%c", node->kontainer.child);
        if (node->kontainer.child && *sumNode != 1)
            printf(" - ");
        *sumNode = *sumNode - 1;
    }
}

simpul* findSimpul(isiKontainer kontainer, simpul *root) {
    simpul *hasil = NULL;
    int mark = 0;
    if (root != NULL) {
        if (root->kontainer.child == kontainer.parent) {
            hasil = root;
        }else {
            hasil = findSimpul(kontainer, root->left);
            if (hasil == NULL) {
                hasil = findSimpul(kontainer, root->right);
            }
        }
    }
    return hasil;
}