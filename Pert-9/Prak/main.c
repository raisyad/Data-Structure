// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include"header.h"

int main(){
  tree T, T2;
  data input;
  data find;
  int count = 0, markDel = 0, tempCount = 0;
  // char find[101];
  // Step 1
  scanf("%s %s", &input.name, &input.value);
  makeTree(input, &T);
  count++;

  scanf("%s %s", &input.name, &input.value);
  addChild(input, T.root);
  count++;
  scanf("%s %s", &input.name, &input.value);
  addChild(input, T.root);
  count++;
  scanf("%s %s", &input.name, &input.value);
  addChild(input, T.root);
  count++;

  scanf("%s %s", &input.name, &input.value);
  addChild(input, T.root->child);
  count++;
  scanf("%s %s", &input.name, &input.value);
  addChild(input, T.root->child);
  count++;
  tempCount = count;

  printf("Step 1:\n");
  printf("================\n");
  printTreePreOrder(T.root, &count);
  count = tempCount;
  printf("\n"); 
  printTreePostOrder(T.root, &count);
  printf("\n");

  delChild(T.root->child->child->sibling, T.root->child);
  markDel++;

  // After Del
  count = tempCount - markDel;
  printTreePreOrder(T.root, &count);
  printf("\n");

  count = tempCount - markDel;
  printTreePostOrder(T.root, &count);
  printf("\n");

  count = tempCount;
  scanf("%s %s", &input.name, &input.value);
  addChild(input, T.root->child->sibling);
  count++;

  scanf("%s %s", &input.name, &input.value);
  addChild(input, T.root->child->sibling);
  count++;

  scanf("%s %s", &input.name, &input.value);
  addChild(input, T.root->child->sibling->sibling);
  count++;
  tempCount = count;

  count = tempCount - markDel;
  printTreePreOrder(T.root, &count);
  printf("\n");

  // Step 2
  copyTree(T.root, &T2.root);
  printf("Step 2:\n");
  printf("================\n");
  if(isEqual(T.root, T2.root) == 1){
    printf("Sama\n");
  }else {
    printf("Tidak Sama\n");
  }

  scanf("%s", &find.name);
  simpul *node = findSimpul(find, T.root->child->child);
  printf("Step 3:\n");
  printf("================\n");
  if (node != NULL){
    printf("%s ditemukan\n", find.name);
  }else {
    printf("%s tidak ditemukan\n", find.name);
  }

  node = findSimpul(find, T.root->child->sibling);
  if (node != NULL){
    printf("%s ditemukan\n", find.name);
  }else {
    printf("%s tidak ditemukan\n", find.name);
  }

  node = findSimpul(find, T.root);
  if (node != NULL){
    printf("%s ditemukan\n", find.name);
  }else {
    printf("%s tidak ditemukan\n", find.name);
  }
  

  // scanf(" %c", &input.a);
  // addChild(input, T.root);
  // scanf(" %c", &input.a);
  // addChild(input, T.root);
  // scanf(" %c", &input.a);
  // addChild(input, T.root);

  // input.a = 'B';
  // simpul *node = findSimpul(input, T.root);
  // if(node != NULL){
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  // }

  // input.a = 'C';
  // node = findSimpul(input, T.root);
  // if(node != NULL){
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  // }

  // input.a = 'D';
  // node = findSimpul(input, T.root);
  // if(node != NULL){
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  // }

  // input.a = 'J';
  // node = findSimpul(input, T.root);
  // if(node != NULL){
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  //   scanf(" %c", &input.a);
  //   addChild(input, node);
  // }

  // printf("=================\n");
  // printf("preOrder\n");
  // printTreePreOrder(T.root);
  // printf("\n=================\n");
  // printf("postOrder\n");
  // printTreePostOrder(T.root);
  // printf("\n=================\n");

  // tree T2;

  // copyTree(T.root, &T2.root);
  // printTreePostOrder(T2.root);
  
  // if(isEqual(T.root, T2.root) == 1){
  //   printf("pohon sama\n");
  // }
  // else{
  //   printf("pohon tidak sama\n");
  // }

  // input.a = 'J';
  // node = findSimpul(input, T.root);
  // if(node != NULL){
  //   input.a = 'K';
  //   delChild(input, node);
  //   input.a = 'L';
  //   delChild(input, node);
  //   input.a = 'M';
  //   delChild(input, node);
  // }
  // printf("=================\n");
  // printf("preOrder setelah dihapus\n");
  // printTreePreOrder(T.root);
  // printf("\n=================\n");
}