// Subset sums by dynamic programming
// CSE 2320 Notes 7

#include <stdio.h>
#include <stdlib.h>

void readInput(int* n,int* m,int** S,int** C) {
    int i;

    scanf("%d",n);
    scanf("%d",m);

    *S=(int*) malloc((*n+1)*sizeof(int));
    *C=(int*) malloc((*m+1)*sizeof(int));

    if (!(*S) || !(*C)) {
      printf("malloc failed %d\n",__LINE__);
      exit(0);
    }

    (*S)[0]=0;

    for (i = 1; i <= *n; i++) {
      scanf("%d", *S + i);
    }
}

void cardSubsetSum(int n,int m,int* S,int* C) {
    int i, j, potentialSum, leftover;
    int card[n][m];

    C[0]=0;

    for (potentialSum=1; potentialSum<=m; potentialSum ++) {
      for (j = 1; j <= n; j++) {
        leftover = potentialSum - S[j];
        if (leftover>=0 && C[leftover]<j) {
          break;
        }
      }
      C[potentialSum]=j;
    }
}

void writeOutput(int n,int m,int* S,int* C) {
    int i;

    printf("  i   S\n");
    printf("-------\n");

    for (i=0;i<=n;i++) {
      printf("%3d %3d\n",i,S[i]);
    }


    if (m <= 50) {
      printf("  i   C\n");
      printf("-------\n");

      for (i = 0 ;i <= m; i++) {
        printf("%3d %3d\n",i,C[i]);
      }
    }


    if (C[m] == n+1) {
      printf("No solution\n");
    }
    else {
      printf("Solution\n");
      printf("  i   S\n");
      printf("-------\n");

      for (i = m; i > 0; i -= S[C[i]]) {
        printf("%3d %3d\n",C[i],S[C[i]]);
      }
    }
}

int main() {
    int n;    // Size of input set
    int m;    // Target value
    int *S;   // Input set
    int *C;   // Cost table

    readInput(&n,&m,&S,&C);

    cardSubsetSum(n,m,S,C);

    writeOutput(n,m,S,C);

    free(S);
    free(C);
}