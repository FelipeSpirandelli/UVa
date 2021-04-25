#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


int main(){

    int X, R, C, M, N;
    int i,j, caso = 0;
    char ch;
    int auxMaxim, total;
    vector<int> maxim, minim;

    scanf("%d", &X);
    while(X--){
        int marks[26] = {};
        scanf("%d %d %d %d", &R, &C, &M, &N);
        rep(i,0,R){
            rep(j,0,C){
                scanf(" %c", &ch);
                marks[ch - 'A']++;
            }
        }
        auxMaxim = 0;
        maxim.clear();
        minim.clear();
        rep(i,0,26){
            if(marks[i] > auxMaxim) {
                rep(j,0,maxim.size()){
                    minim.push_back(maxim[j]);
                }
                maxim.clear();
                maxim.push_back(i);
                auxMaxim = marks[i];
            }
            else if(marks[i] == auxMaxim){
                maxim.push_back(i);
            }
            else minim.push_back(i);
        }
        total = 0;
        rep(i,0,maxim.size()){
            total += marks[maxim[i]] * M;
        }
        rep(i,0,minim.size()){
            total += marks[minim[i]] * N;
        }
        printf("Case %d: %d\n", ++caso, total);
    }

    return 0;
}

