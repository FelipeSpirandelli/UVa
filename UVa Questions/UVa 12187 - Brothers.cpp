#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

void take(int A[][100], int R, int C, int N){
    int i,j;
    int B[100][100];
    //if you change A positions directly, some changes may alter an element before it changes its environment 
    rep(i,0,R){
        rep(j,0,C){
            B[i][j] = A[i][j];
        }
    }
    rep(i,0,R){
        rep(j,0,C){
            if(i>0)if(B[i-1][j] == (B[i][j] + 1)%N) A[i-1][j] = B[i][j];
            if(i<R-1)if(B[i+1][j] == (B[i][j] + 1)%N) A[i+1][j] = B[i][j];
            if(j>0)if(B[i][j-1] == (B[i][j] + 1)%N) A[i][j-1] = B[i][j];
            if(j<C-1)if(B[i][j+1] == (B[i][j] + 1)%N) A[i][j+1] = B[i][j];
        }
    }
}

int main()
{
    int N, R, C, K;
    int land[100][100];
    int i,j;



    while(scanf("%d %d %d %d", &N, &R, &C, &K) && N && R){
        rep(i,0,R){
            rep(j,0,C){
                scanf("%d", &land[i][j]);
            }
        }
        while(K--){
            take(land, R, C, N);
        }

        rep(i,0,R){
            rep(j,0,C-1){
                printf("%d ", land[i][j]);
            }
            printf("%d", land[i][C-1]);
            printf("\n");
        }

    }

    return 0;
}

