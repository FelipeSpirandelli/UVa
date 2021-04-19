/*
The only detail is that there are some test cases in which the cars
won or lost a impossible number of positions
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;



int main()
{
    freopen("input.txt", "r", stdin);

    int N;
    int i;

    while(scanf("%d", &N) == 1 && N){
        int cars[10000], positions[1005];
        int marks[1005] = {};
        int flag = 0;
        for(i=0;i<N;i++){
            scanf("%d %d", &cars[i], &positions[i]);
            //actual positions is i + its winning or losing positions
            if(i+positions[i] < N && i+positions[i] >= 0) marks[i + positions[i]]++;
            else flag++;
        }
        if(flag>0){
            printf("-1\n");
            continue;
        }
        int initial_positions[1005];
        rep(i,0,N){
            if(marks[i + positions[i]] == 1){
                initial_positions[i+positions[i]] = cars[i];
            }
            else{
                flag++;
                break;
            }
        }
        if(flag == 0){
            printf("%d", initial_positions[0]);
            for(i=1;i<N;i++){
                printf(" %d", initial_positions[i]);
            }
            printf("\n");
        }
        else printf("-1\n");
    }


    return 0;
}
