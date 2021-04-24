#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


void click(int a[][3], char b){

    switch(b){
        case 'a':
            ++a[0][0]%=10;
            ++a[0][1]%=10;
            ++a[1][0]%=10;
            break;
        case 'b':
            ++a[0][0]%=10;
            ++a[0][1]%=10;
            ++a[0][2]%=10;
            ++a[1][1]%=10;
            break;
        case 'c':
            ++a[0][2]%=10;
            ++a[0][1]%=10;
            ++a[1][2]%=10;
            break;
        case 'd':
            ++a[0][0]%=10;
            ++a[1][0]%=10;
            ++a[2][0]%=10;
            ++a[1][1]%=10;
            break;
        case 'e':
            ++a[1][1]%=10;
            ++a[0][1]%=10;
            ++a[1][2]%=10;
            ++a[2][1]%=10;
            ++a[1][0]%=10;
            break;
        case 'f':
            ++a[1][2]%=10;
            ++a[1][1]%=10;
            ++a[0][2]%=10;
            ++a[2][2]%=10;
            break;
        case 'g':
            ++a[2][0]%=10;
            ++a[1][0]%=10;
            ++a[2][1]%=10;
            break;
        case 'h':
            ++a[2][1]%=10;
            ++a[2][0]%=10;
            ++a[1][1]%=10;
            ++a[2][2]%=10;
            break;
        case 'i':
            ++a[2][2]%=10;
            ++a[1][2]%=10;
            ++a[2][1]%=10;
            break;
        default:
            break;
    }

}



int main(){
    char commands;
    int i,j, caso = 0;
    int a[3][3] = {};

    while(scanf("%c", &commands) != EOF){
        click(a, commands);
        if(commands == '\n'){
            printf("Case #%d:\n", ++caso);
            rep(i,0,3){
                rep(j,0,2){
                    printf("%d ", a[i][j]);
                }
                printf("%d\n", a[i][2]);
            }
            rep(i,0,3){
                rep(j,0,3){
                    a[i][j] = 0;
                }
            }
        }
    }
    return 0;
}

