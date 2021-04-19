#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;



    void rotation90(char A[][10], char B[][10], int N){
        int i,j;
        rep(i,0,N){
            rep(j,0,N){
                B[j][(N-1)-i] = A[i][j];
            }
        }
    }
    void reflex(char A[][10], char B[][10], int N){
        int i,j;
        rep(i,0,N){
            rep(j,0,N){
                B[(N-1)-i][j] = A[i][j];
            }
        }
    }

    bool compare(char A[][10], char B[][10], int N){
        int i,j, flag = 0;
        rep(i,0,N){
            rep(j,0,N){
                if(A[i][j] != B[i][j]){
                    flag++;
                    break;
                }
            }
        }
        if(flag == 0)return true;
        else return false;
    }

int main()
{
    int N;
    int i,j;
    int caso = 0;

    while(scanf("%d", &N) == 1){
        char original[10][10], transformed[10][10];
        rep(i,0,N){
            rep(j,0,N){
                scanf(" %c", &original[i][j]);
            }
            rep(j,0,N){
                scanf(" %c", &transformed[i][j]);
            }
        }
        char ori90[10][10], ori180[10][10], ori270[10][10], oriVer[10][10], oriVer90[10][10], oriVer180[10][10], oriVer270[10][10];
        if(compare(original,transformed, N)){
            printf("Pattern %d was preserved.\n", ++caso);
            continue;
        }
        rotation90(original, ori90, N);
        if(compare(ori90,transformed, N)){
            printf("Pattern %d was rotated 90 degrees.\n", ++caso);
            continue;
        }
        rotation90(ori90, ori180, N);
        if(compare(ori180,transformed, N)){
            printf("Pattern %d was rotated 180 degrees.\n", ++caso);
            continue;
        }
        rotation90(ori180, ori270, N);
        if(compare(ori270,transformed, N)){
            printf("Pattern %d was rotated 270 degrees.\n", ++caso);
            continue;
        }
        reflex(original, oriVer, N);
        if(compare(oriVer, transformed, N)){
            printf("Pattern %d was reflected vertically.\n", ++caso);
            continue;
        }
        rotation90(oriVer, oriVer90, N);
        if(compare(oriVer90, transformed, N)){
            printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", ++caso);
            continue;
        }
        rotation90(oriVer90, oriVer180, N);
        if(compare(oriVer180, transformed, N)){
            printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", ++caso);
            continue;
        }
        rotation90(oriVer180, oriVer270, N);
        if(compare(oriVer270, transformed, N)){
            printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", ++caso);
            continue;
        }
        printf("Pattern %d was improperly transformed.\n", ++caso);

    }
    return 0;
}

