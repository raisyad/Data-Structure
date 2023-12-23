#include"header.h"

int main(){
  tree T;
  data input;

  scanf(" %c", &input.a);
  makeTree(input, &T);

  scanf(" %c", &input.a);
  addChild(input, T.root);
  scanf(" %c", &input.a);
  addChild(input, T.root);
  scanf(" %c", &input.a);
  addChild(input, T.root);

  input.a = 'B';
  simpul *node = findSimpul(input, T.root);
  if(node != NULL){
    scanf(" %c", &input.a);
    addChild(input, node);
    scanf(" %c", &input.a);
    addChild(input, node);
  }

  input.a = 'C';
  node = findSimpul(input, T.root);
  if(node != NULL){
    scanf(" %c", &input.a);
    addChild(input, node);
  }

  input.a = 'D';
  node = findSimpul(input, T.root);
  if(node != NULL){
    scanf(" %c", &input.a);
    addChild(input, node);
    scanf(" %c", &input.a);
    addChild(input, node);
    scanf(" %c", &input.a);
    addChild(input, node);
  }

  input.a = 'J';
  node = findSimpul(input, T.root);
  if(node != NULL){
    scanf(" %c", &input.a);
    addChild(input, node);
    scanf(" %c", &input.a);
    addChild(input, node);
    scanf(" %c", &input.a);
    addChild(input, node);
  }

  printf("=================\n");
  printf("preOrder\n");
  printTreePreOrder(T.root);
  printf("\n=================\n");
  printf("postOrder\n");
  printTreePostOrder(T.root);
  printf("\n=================\n");

  tree T2;

  copyTree(T.root, &T2.root);
  printTreePostOrder(T2.root);
  
  if(isEqual(T.root, T2.root) == 1){
    printf("pohon sama\n");
  }
  else{
    printf("pohon tidak sama\n");
  }

  input.a = 'J';
  node = findSimpul(input, T.root);
  if(node != NULL){
    input.a = 'K';
    delChild(input, node);
    input.a = 'L';
    delChild(input, node);
    input.a = 'M';
    delChild(input, node);
  }
  printf("=================\n");
  printf("preOrder setelah dihapus\n");
  printTreePreOrder(T.root);
  printf("\n=================\n");

  return 0;
}