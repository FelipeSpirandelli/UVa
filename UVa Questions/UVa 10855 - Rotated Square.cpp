#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


void rotate90(char A[][100], char B[][100], int n){
    int i,j;
    rep(i,0,n){
        rep(j,0,n){
            B[j][(n-1)-i] = A[i][j];
        }
    }
}

int comparing( char A[][100], char B[][100], int N, int n){
    int i,j,k,l;
    int flag, total = 0;
    rep(l,0,N-n+1){
        rep(k,0,N-n+1){
            flag = 0;
            rep(i,0,n){
                rep(j,0,n){
                    if(A[l+i][k+j] != B[i][j]){
                        flag++;
                        break;
                    }
                }
                    if(flag != 0) break;
            }
            if(flag == 0) total++;
        }
    }
    return total;
}


int main()
{
    int N, n;
    int i,j;
    int total, total90, total180, total270;

    while(scanf("%d %d", &N, &n) && N){
        char big[100][100], small[100][100];
        rep(i,0,N){
            //throwing away the \n
            scanf("%*c");
            rep(j,0,N){
                scanf("%c", &big[i][j]);
            }
        }
        rep(i,0,n){
            //throwing away the \n
            scanf("%*c");
            rep(j,0,n){
                scanf("%c", &small[i][j]);
            }
        }
        total = comparing(big, small, N, n);
        char small90[100][100], small180[100][100], small270[100][100];

        rotate90(small, small90, n);
        total90 = comparing(big, small90, N, n);

        rotate90(small90, small180, n);
        total180 = comparing(big, small180, N, n);

        rotate90(small180, small270, n);
        total270 = comparing(big, small270, N, n);

        printf("%d %d %d %d\n", total, total90, total180, total270);

    }
    return 0;
}

