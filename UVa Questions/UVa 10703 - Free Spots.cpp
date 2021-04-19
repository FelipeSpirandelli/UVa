/*
Be careful with X1>X2 or Y1>Y2
*/

#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


int main()
{
    int W, H, N;
    int X1, X2, Y1, Y2;
    int i, j;

    while(scanf("%d %d %d", &W, &H, &N) && W ){
        int board[500][500] = {};
        while(N--){
            scanf("%d %d %d %d", &X1, &Y1 ,&X2, &Y2);
            if(X2<X1)swap(X1,X2);
            if(Y2<Y1)swap(Y1,Y2);
            rep(i,X1-1,X2){
                rep(j,Y1-1,Y2){
                    board[i][j] = 1;
                }
            }
        }
        int total = 0;
        rep(i,0,W){
            rep(j,0,H){
                if(board[i][j] == 0) total++;
            }
        }
        if(total == 0) printf("There is no empty spots.\n");
        else if(total == 1) printf("There is one empty spots.\n");
        else printf("There are %d empty spots.\n", total);
    }

    return 0;
}

