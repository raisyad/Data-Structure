// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM7 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void){
  queue Q;
  queue Q2;
  IsiKontainer input;
  
  createEmpty(&Q);
  createEmpty(&Q2);

  scanf("%s %s", &input.GameName, &input.GameRating);
  add(input, &Q);
  scanf("%s %s", &input.GameName, &input.GameRating);
  add(input, &Q);
  scanf("%s %s", &input.GameName, &input.GameRating);
  addPriority(input, &Q, 2);
  printf("******************\n");
  printf("Queue 1\n");
  printQueue(Q);
  DeltoInS(&Q, &Q2);

  printf("******************\n");
  printf("Queue 1\n");
  printQueue(Q);
  printf("******************\n");
  printf("Queue 2\n");
  printQueue(Q2);

  scanf("%s %s", &input.GameName, &input.GameRating);
  addPriority(input, &Q, 1);
  scanf("%s %s", &input.GameName, &input.GameRating);
  addPriority(input, &Q, 99);

  printf("******************\n");
  printf("Queue 1\n");
  printQueue(Q);

  DeltoInS(&Q, &Q2);
  DeltoInS(&Q, &Q2);
  scanf("%s %s", &input.GameName, &input.GameRating);
  add(input, &Q);

  printf("******************\n");
  printf("Queue 1\n");
  printQueue(Q);
  printf("******************\n");
  printf("Queue 2\n");
  printQueue(Q2);
  printf("******************\n");

  // printf("=================\n");
  // delLast(&Q);
  // // del(&Q);
  // // del(&Q);
  // printQueue(Q);
  // printf("=================\n");
}


/*

input--

3
13507701 Nana 64.75
13507702 Rudi 75.11
13507703 Dea 84.63

*/