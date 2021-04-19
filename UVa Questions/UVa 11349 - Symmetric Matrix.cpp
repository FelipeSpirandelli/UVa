#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

int main()
{
    int T, N, caso = 0;
    int i,j;
    int flag;

    scanf("%d", &T);
    while(T--){
        flag = 0;
        long long int matrix[105][105];
        scanf(" %*c %*c %d", &N);
        rep(i,0,N){
            rep(j,0,N){
                scanf("%lld",&matrix[i][j]);
                if(matrix[i][j] < 0) flag++;
            }
        }
        if(flag==0){
            rep(i,0,N/2+1){
                rep(j,0,N){
                    if(matrix[i][j] != matrix[(N-1)-i][(N-1)-j]){
                        flag++;
                        break;
                    }
                }
            }
        }
        if(flag == 0) printf("Test #%d: Symmetric.\n", ++caso);
        else printf("Test #%d: Non-symmetric.\n", ++caso);
    }

    return 0;
}

