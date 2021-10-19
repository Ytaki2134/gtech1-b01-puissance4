#include <stdio.h>
#define NBL 6
#define NBC 7

int tab[NBL][NBC];
int i, j;

void init(void) {
 printf("-------------\n");
  for(i=0; i < NBL; i++) {
    for(j = 0; j < NBC; j++)
    {
      printf(". ",tab[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
  printf("1 2 3 4 5 6 7\n");
}

void main(void) {
  init();
}