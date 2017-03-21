#include <stdio.h>
#include <stdlib.h>

void readInput(int* n, int* m, int** S) {
  // Loads all input and allocates space
  int i;

  scanf("%d",n);
  scanf("%d",m);

  *S=(int*) malloc((*n+1)*sizeof(int));
  //*C=(int*) malloc((*m+1)*sizeof(int));

  if (!(*S)) {
    printf("malloc failed %d\n",__LINE__);
    exit(0);
  }

  // Sentinel zero
  (*S)[0] = 0;

  for (i = 1; i <= *n; i++) {
    scanf("%d", *S+i);
  }
}

void subsetSum(int n, int m, int* S) {
  int i, k;
  int index[m+1];
  int C[25][7];
  int sizeIndex = sizeof(index)/sizeof(index[0]);

  printf("\n");

  for (i = 0; i < sizeIndex; i++) {
    index[i] = i;
  }

  for (i = 0; i < sizeIndex; i++) {
    for (k = 0; k < n; k++) {
      if ((((index[i] - S[k]) >= 0) && ((index[i] - (S)[k]) != index[i])) && ((index[i] - S[k]) > C[i-1][k]))  {
        //printf("%d %d\n", S[k], index[i]);
        //printf("good\n");
        C[i-1][k] = k;
      }
      else {
        //printf("%d %d\n", S[k], index[i]);
        //printf("bad\n");
        C[i-1][k] = 8;
      }
    }
    printf("\n-----------\n");
  }

  for (i = 0; i < sizeIndex; i++) {
    for (k = 0; k < n; k++) {
      printf("%d ", C[i-1][k]);
    }
    printf("\n");
  }
}


int main() {
  int n;    // Size of input set
  int m;    // Target value
  int *S;   // Input set
  int *C;   // Cost table

  readInput(&n,&m,&S);

  subsetSum(n,m,S);

  free(S);
  free(C);
}
