#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


int main()
{
    int n;
    int i,j;
    int flagLine, flagColumn, line, column;

    while(scanf("%d", &n) == 1 && n){
        int matrix[100][100];
        int lineSum[100] = {}, columnSum[100] = {};

        rep(i,0,n){
            rep(j,0,n){
                scanf("%d", &matrix[i][j]);
                lineSum[i] += matrix[i][j];
                columnSum[j] += matrix[i][j];
            }
        }
        flagLine = 0;
        line = -1;
        rep(i,0,n){
            if(lineSum[i]%2 != 0){
             flagLine++;
             line = i;
            }
        }
        flagColumn = 0;
        column = -1;
        rep(i,0,n){
            if(columnSum[i]%2 != 0){
             flagColumn++;
             column = i;
            }
        }
        if(flagLine == 0 && flagColumn == 0) printf("OK\n");
        else if(flagLine == 1 && flagColumn == 1) printf("Change bit (%d,%d)\n", line +1 , column +1);
        else printf("Corrupt\n");
    }


    return 0;
}

