#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int N;
    int i,j;

    scanf("%d", &N);

    while(N--){
        int blocks[100][100] = {};
        for(i=0;i<9;i+=2){
            for(j=0;j<=i;j+=2){
                scanf("%d", &blocks[i][j]);
            }
        }
        for(i=2;i<9;i+=2){
            for(j=1;j<=i;j+=2){
                blocks[i][j] = (blocks[i-2][j-1] - blocks[i][j-1] - blocks[i][j+1])/2;
            }
        }
        for(i=1;i<9;i+=2){
            for(j=0;j<=i;j++){
                blocks[i][j] = blocks[i+1][j] + blocks[i+1][j+1];
            }
        }
        rep(i,0,9){
            for(j=0;j<i;j++){
                printf("%d ", blocks[i][j]);
            }
            printf("%d\n", blocks[i][i]);
        }
    }

    return 0;
}

