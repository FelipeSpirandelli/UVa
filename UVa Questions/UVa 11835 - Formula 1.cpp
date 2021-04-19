#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

int main()
{

   int G, P, Sys, Sys_max;
   int i,j,k, maxim;

   while(scanf("%d %d", &G, &P) && G){
        int pilots[105][105] = {}, pointsSys[105];
        rep(j,0,G){
            rep(i,0,P){
                scanf("%d", &pilots[i][j]);
            }
        }
        scanf("%d", &Sys);
        rep(i,0,Sys){
            int pointsPilots[105] = {};
            scanf("%d", &Sys_max);
            rep(j,0,Sys_max){
                scanf("%d", &pointsSys[j]);
            }
            rep(j,0,G){
                rep(k,0,P){
                    if(pilots[k][j] <= Sys_max)pointsPilots[k] += pointsSys[pilots[k][j] - 1];
                }
            }
            maxim = -1;
            int index[105] = {};
            rep(j,0,P){
                if(pointsPilots[j] > maxim){
                    k = 0;
                    maxim = pointsPilots[j];
                    index[k] = j;
                    k++;
                }
                else if(pointsPilots[j] == maxim){
                    index[k] = j;
                    k++;
                }
            }
            rep(j,0,k-1){
                printf("%d ", index[j]+1);
            }
            printf("%d", index[k-1]+1);
            printf("\n");
        }

   }
    return 0;
}

