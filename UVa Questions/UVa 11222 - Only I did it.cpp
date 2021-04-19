//Solution almost taken from Morris
//Thanks for the help :) 
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    int i,j, caso = 0;
    int auxMaxim, maxim;
    scanf("%d", &T);

    while(T--){
        int marks[10001] = {};
        int livros[3][10001], A[3];
        for(i=0;i<3;i++){
            scanf("%d", &A[i]);
            for(j=0;j<A[i];j++){
                scanf("%d", &livros[i][j]);
                marks[livros[i][j]]++;
            }
            sort(livros[i], livros[i] + A[i]);
        }
        int diferencas[3];
        maxim = 0;
        for(i=0;i<3;i++){
            auxMaxim = 0;
            for(j=0;j<A[i];j++){
                if(marks[livros[i][j]] == 1){
                    auxMaxim++;
                }
            }
            diferencas[i] = auxMaxim;
            if(auxMaxim>maxim) maxim = auxMaxim;
        }
        printf("Case #%d:\n", ++caso);
        for(j=0;j<3;j++){
            if(diferencas[j] == maxim){
                printf("%d %d", j+1, diferencas[j]);
                for(i=0;i<A[j];i++){
                    if(marks[livros[j][i]] == 1){
                        printf(" %d", livros[j][i]);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}

