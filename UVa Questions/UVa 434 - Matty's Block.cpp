#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;



int main()
{
    int T, K, h, N, M;
    int i,j,k,flag;

    scanf("%d", &T);
    while(T--){
        N = 0;
        M = 0;
        int marksFront[8][8] = {}, marksSide[8][8] = {};
        scanf("%d", &K);
        rep(i,0,K){
            scanf("%d", &h);
            rep(j,0,h){
                marksFront[i][j]++;
            }
        }
        rep(i,0,K){
            scanf("%d", &h);
            rep(j,0,h){
                marksSide[i][j]++;
            }
        }
        rep(i,0,K){
            rep(j,0,K){
                rep(k,0,8){
                    if(marksFront[i][k] == 1 && marksSide[j][k] == 1){
                        M++;
                    }
                }
            }
        }
        rep(i,0,K){
            rep(j,0,K){
                flag = 0;
                if(marksFront[i][0] == 1 && marksSide[j][0] == 1){
                    rep(k,1,8){
                        if( marksFront[i][k] != marksSide[j][k]) flag++;
                        if(marksFront[i][k] == 0 && marksSide[j][k] == 0) break;
                    }
                    if(flag==0){
                        N+=k;
                        rep(k,0,8){
                            marksFront[i][k] = 0;
                            marksSide[j][k] = 0;
                        }
                    }
                }
            }
        }
        rep(i,0,K){
            rep(k,0,8){
                if(marksFront[i][k] == 1) N++;
            }
        }
         rep(i,0,K){
            rep(k,0,8){
                if(marksSide[i][k] == 1) N++;
            }
        }

    printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", N, M-N);
    }


    return 0;
}

