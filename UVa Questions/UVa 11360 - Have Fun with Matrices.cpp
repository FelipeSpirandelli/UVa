#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


void row(int A[][10], int a, int b, int N){
    int j;
    int aux;
    rep(j,0,N){
        aux = A[a][j];
        A[a][j] = A[b][j];
        A[b][j] = aux;
    }
}
void column(int A[][10], int a, int b, int N){
    int i;
    int aux;
    rep(i,0,N){
        aux = A[i][a];
        A[i][a] = A[i][b];
        A[i][b] = aux;
    }
}
void inc(int A[][10], int N){
    int i,j;
    rep(i,0,N){
        rep(j,0,N){
            A[i][j]++;
            if(A[i][j] == 10) A[i][j] = 0;
        }
    }
}
void decr(int A[][10], int N){
    int i,j;
    rep(i,0,N){
        rep(j,0,N){
            A[i][j]--;
            if(A[i][j] == -1) A[i][j] = 9;
        }
    }
}
void transpose(int A[][10], int N){
    int i,j;
    int aux;
    rep(i,0,N){
        rep(j,i,N){
           aux = A[i][j];
           A[i][j] = A[j][i];
           A[j][i] = aux;
        }
    }
}
int main()
{
    int T, caso = 0, N, M;
    int i, j;
    int a,b;
    char command[10];
    scanf("%d", &T);

    while(T--){
        int matrix[10][10];
        scanf("%d", &N);
        rep(i,0,N){
            rep(j,0,N){
                scanf("%1d", &matrix[i][j]);
            }
        }
        scanf("%d", &M);
        while(M--){
            scanf(" %s", command);
            if(command[0]=='r'){
                scanf("%d %d", &a, &b);
                row(matrix, a-1, b-1 , N);
            }
            else if(command[0]=='c'){
                scanf("%d %d", &a, &b);
                column(matrix, a-1, b-1 , N);
            }
            else if(command[0] == 'i'){
                inc(matrix,N);
            }
            else if(command[0] == 'd'){
                decr(matrix, N);
            }
            else if(command[0] == 't'){
                transpose(matrix,N);
            }
        }
        printf("Case #%d\n", ++caso);
        rep(i,0,N){
            rep(j,0,N){
                printf("%d", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }


    return 0;
}

