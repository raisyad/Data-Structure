#include "header.h"

void makeTree(int akar, tree *T)
{

    simpul *baru;
    baru = (simpul *) malloc (sizeof(simpul));

    baru->kontainer.c = akar;
    baru->right = NULL;
    baru->left = NULL;

    (*T).root = baru;
    baru = NULL;
}

void addRight(int akar, simpul *node)
{
    
    if(node != NULL)
    {
    	if(node->right == NULL)
	    {
	        /*jika sub pohon kanan kosong*/
	        simpul *baru;
	        baru = (simpul *) malloc (sizeof (simpul));

	        baru->kontainer.c = akar;
	        baru->right = NULL;
	        baru->left = NULL;
	        
	        node->right = baru;
	        baru = NULL;
	    }
    }
}

void addLeft(int akar, simpul *node)
{
	if(node != NULL)
	{
		if(node->left == NULL)
	    {
	        /*jika sub pohon kiri kosong*/
	        simpul *baru;
	        baru = (simpul *) malloc (sizeof (simpul));

	        baru->kontainer.c = akar;
	        baru->right = NULL;
	        baru->left = NULL;

	        node->left = baru;
	        baru = NULL;
	    }
	}
}

void delAll(simpul *node)
{

    if(node != NULL)
    {
        delAll(node->left);
        delAll(node->right);
        free(node);
    }
}

void delRight(simpul *node)
{

    if(node != NULL)
    {
        if(node->right != NULL)
        {
            delAll(node->right);
            node->right = NULL;
        }
    }
}

void delLeft(simpul *node)
{

    if(node != NULL)
    {
        if(node->left != NULL)
        {
            delAll(node->left);
            node->left = NULL;
        }
    }
}

void printTreePreOrder(simpul *node, int idx)
{
    if(node != NULL)
    {
        if(idx == 0)
        {
            printf("%d", node->kontainer);
            idx++;
        }
        else
        {
            printf("-%d", node->kontainer);
        }
        printTreePreOrder(node->left, idx);
        printTreePreOrder(node->right, idx);
    }
}

void printTreeInOrder(simpul *node)
{

    if(node != NULL)
    {
        printTreeInOrder(node->left);
        printf(" %d ", node->kontainer);
        printTreeInOrder(node->right);
    }
}

void printTreePostOrder(simpul *node)
{

    if(node != NULL)
    {
        printTreePostOrder(node->left);
        printTreePostOrder(node->right);
        printf(" %d ", node->kontainer);
    }
}

void copyTree(simpul *node1, simpul**node2)
{

    if(node1 != NULL)
    {
        (*node2) = (simpul *) malloc (sizeof(simpul));
        (*node2)->kontainer = node1->kontainer;
        if(node1->left != NULL)
        {
            copyTree(node1->left, &(*node2)->left);
        }
        if(node1->right != NULL)
        {
            copyTree(node1->right, &(*node2)->right);
        }
    }
}

int isEqual(simpul *node1, simpul *node2)
{
    if((node1 != NULL)&&(node2 != NULL))
    {
        /* jika simpul pohon 1 dan pohon 2 sama sama
        tidak NULL */
        if(node1->kontainer.c != node2->kontainer.c)
        {
            /* jika isi kontainer simpul pohon 1 dan pohon
            2 tidak sama */
            return 0;
        }
        else
        {
            /* jika isi kontainer simpul pohon 1 dan simpul
            pohon 2 sama, maka telusuri simpul selanjutnya */
            if(isEqual(node1->left,node2->left) == 0 || isEqual(node1->right,node2->right) == 0)
            {
                return 0;
            }
        }
    }
    else
    {
        if((node1 != NULL)||(node2 != NULL))
        {
            /* jika salah satu simpul ada yang NULL */
            return 0;
        }
    }

    return 1;
}

simpul* findSimpul(int cari, simpul *node)
{
    simpul *hasil = NULL;
    if (node != NULL) 
    {
        if (node->kontainer.c == cari) 
        {
            hasil = node;
        }
        else 
        {
            hasil = findSimpul(cari, node->left);
            if (hasil == NULL) 
            {
                hasil = findSimpul(cari, node->right);
            }
        }
    }
    return hasil;
}



void devide(simpul *node, int akar, int bagi)
{
    int flag = 0;
    if (bagi == 1) {
        flag = 1;
    }
    if (flag != 1) {
        int temp = akar / bagi;
        if(temp > 0)
        {
            if(temp % 2 == 0)
            {
                addLeft(temp, node);
                devide(node->left, temp, bagi);
            }  
            else if(temp % 2 != 0)
            {
                addRight(temp, node);
                devide(node->right, temp, bagi);
            }
        }
    }
}