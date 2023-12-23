#include "header.h"

int main(void) {
    int count = 0, tempCount = 0, markDel = 1, n;
    tree T;
    isiKontainer input;

    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d %s", &input.child, &input.parent, &input.sub);
        if (strcmp(input.sub, "akar") == 0) {
            makeTree(input, &T);
        }else {
            if (strcmp(input.sub, "kiri") == 0) {
                simpul *find = findSimpul(input, T.root);
                addLeft(input, find);
            }else if (strcmp(input.sub, "kanan") == 0) {
                simpul *find = findSimpul(input, T.root);
                addRight(input, find);
            }
        }
    }

    delAll(T.root->right);
    T.root->right = NULL;
    int sum = 0;
    Process(T.root, &sum);
    printf ("%d\n", sum);
}