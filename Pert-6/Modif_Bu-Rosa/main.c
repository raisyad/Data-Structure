#include "header.h"

int main(void) {
  stack S;
  data input;

  createEmpty(&S);

  int n, m, markDel = 0;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%s %s %s", &input.nim, &input.nama, &input.nilai);
    push(input, &S);
  }
  scanf ("%d", &m);

  printStack(S);
  printf ("\n");
  for (int i = 0; i < m; i++) {
    pop(&S);
    markDel++;
  }

  // pop(&S);
  // pop(&S);

  printStack(S);

  // ==== Delete Sisa, harus ada penanda sudah ada berapa yang didelete
  // for(int i=0; i<n-m; i++)
  //   pop(&S);
  // ====

  for(int i=0; i<n-markDel; i++)
    pop(&S);
  
  printStack(S);
}