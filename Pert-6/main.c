#include "header.h"

int main(void) {
  stack S;
  data input;

  createEmpty(&S);

  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%s %s %s", &input.nim, &input.nama, &input.nilai);
    push(input, &S);
  }

  printStack(S);

  pop(&S);
  pop(&S);

  printStack(S);

  // ==== Delete Sisa, harus ada penanda sudah ada berapa yang didelete
  // for(int i=0; i<n-m; i++)
  //   pop(&S);
  // ====

  for(int i=0; i<n; i++)
    pop(&S);
  
  printStack(S);
}