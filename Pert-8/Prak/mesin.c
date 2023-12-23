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
            baru->kontainer.node = kontainer.node;
            baru->right = NULL;
            baru->left = NULL;
            node->right = baru;
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
            baru->kontainer.node = kontainer.node;
            baru->right = NULL;
            baru->left = NULL;
            node->left = baru;
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
        printf("%c", node->kontainer.node);
        if (node->kontainer.node && *sumNode != 1)
            printf(" - ");
        *sumNode = *sumNode - 1;
        printTreePreOrder(node->left, sumNode);
        printTreePreOrder(node->right, sumNode);
    }
}

void printTreeInOrder(simpul *node, int *sumNode) {
    if (node != NULL) {
        printTreeInOrder(node->left, sumNode);
        printf("%c", node->kontainer.node);
        if (node->kontainer.node && *sumNode != 1)
            printf(" - ");
        
        *sumNode = *sumNode - 1;
        printTreeInOrder(node->right, sumNode);
    }
}

void printTreePostOrder(simpul *node, int *sumNode) {
    if (node != NULL) {
        printTreePostOrder(node->left, sumNode);
        printTreePostOrder(node->right, sumNode);
        printf("%c", node->kontainer.node);
        if (node->kontainer.node && *sumNode != 1)
            printf(" - ");
        *sumNode = *sumNode - 1;
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

int isEqual(simpul *root1, simpul *root2){
    if((root1 != NULL)&&(root2 != NULL)){
        /* jika simpul pohon 1 dan pohon 2 sama sama
        tidak NULL */
        if(root1->kontainer.node != root2->kontainer.node)
            /* jika isi kontainer simpul pohon 1 dan pohon 2 tidak sama */
            return 0;
        else{
            printf(" %c = %c\n",root1->kontainer.node, root2->kontainer.node);
            /* jika isi kontainer simpul pohon 1 dan simpul
            pohon 2 sama, maka telusuri simpul selanjutnya */
            if(isEqual(root1->left,root2->left) == 0 || isEqual(root1->right,root2->right) == 0)
                return 0;
        }
    }
    else{
        if((root1 != NULL)||(root2 != NULL))
            /* jika salah satu simpul ada yang NULL */
            return 0;
    }
    return 1;

}