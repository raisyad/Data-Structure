#include "header.h"

void makeTree(isiKontainer kontainer, tree *T) {
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    //
    strcpy(baru->kontainer.node, kontainer.node);
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
            strcpy(baru->kontainer.node, kontainer.node);
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
            strcpy(baru->kontainer.node, kontainer.node);
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

void printTreePreOrder(simpul *node) {
    int mark = 0;
    if (node != NULL) {
        printf("%s", node->kontainer.node);
        printTreePreOrder(node->left);
        printTreePreOrder(node->right);
    }
}

void printTreeInOrder(simpul *node, int *sumNode) {
    if (node != NULL) {
        printTreeInOrder(node->left, sumNode);
        printf("%s", node->kontainer.node);
        if (node->kontainer.node && *sumNode != 1)
            printf(" - ");
        
        *sumNode = *sumNode - 1;
        printTreeInOrder(node->right, sumNode);
    }
}

void printTreePostOrder(simpul *node) {
    if (node != NULL) {
        printTreePostOrder(node->left);
        printTreePostOrder(node->right);
        printf("%s", node->kontainer.node);
        // if (node->kontainer.node && *sumNode != 1)
        //     printf(" - ");
        // *sumNode = *sumNode - 1;
    }
}

void copyTree(simpul *node1, simpul **node2) {
    if (node1 != NULL) {
        (*node2) = (simpul *)malloc(sizeof(simpul));
        strcpy((*node2)->kontainer.node, node1->kontainer.node);
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

simpul* findSimpul(isiKontainer input, simpul *node){
    int ketemu = 0;
    simpul *hasil = NULL;
    if(node != NULL){
        if (ketemu == 0) {
            hasil = findSimpul(input, node->left);
            if (strcmp(hasil->kontainer.node, input.node) == 0){
                ketemu = 1;
            }
            hasil = findSimpul(input, node->right);
        }
    }
    return hasil;
}

void modifyData(char word[]) {
    tree T;
    int len = 0, iterChild = 0, iterChildFromParent = 0, counts = 0, count = 1;
    len = strlen(word);
    isiKontainer input;
    // printf("%d\n", len);
    char Name[102], child[102], childFromParent[102];
    int markParent = 0;

    for (int i = 0; i < len; i++) {
        if ((word[i] != ' ' && word[i] != ';') && markParent == 0) {
            Name[i] = word[i];
        }else if ((word[i] == ' ' || word[i] == ';') && markParent == 0) {
            Name[i] = '\0';
            markParent = 1;
        }else if ((word[i] != ' ' && word[i] != ';') && counts == 0){
            child[iterChild] = word[i];
            iterChild++;
        }else if ((word[i] == ' ' || word[i] == ';') && counts == 0){
            child[iterChild] = '\0';
            counts++;
        }else if (word[i] != ';' && counts == 1) {
            childFromParent[iterChildFromParent] = word[i];
            iterChildFromParent++;
        }else if (word[i] == ';' && counts == 1){
            child[iterChildFromParent] = '\0';
            counts++;
        }
    }
    // printf ("%s --\n", Name);
    // printTreePreOrder(T.root);

    if (strcmp(Name, "MAKETREE") == 0){
        strcpy(input.node,child);
        printf("%s - ", Name);
        printf("%s - if1\n", child);
        // strcpy(&input,Name);
        makeTree(input, &T);
        printf("%s\n", input.node);
        printTreePreOrder(T.root);
        printf("\n");
    }else if (strcmp(Name, "CHILD") == 0){
        strcpy(input.node,child);

        // addLeft(input, T.root->right);
        printf("%s - ", Name);
        printf("%s - ", child);
        printf("%s - if2\n", childFromParent);
    }else if (strcmp(Name, "DELLCHILD") == 0){
        printf("%s - ", Name);
        printf("%s - ", child);
        printf("%s - if3\n", childFromParent);
    }else if (strcmp(Name, "PREORDER") == 0){
        printf("%s - if4\n", Name);
        printTreePreOrder(T.root);
        printf("\n");
    }

}