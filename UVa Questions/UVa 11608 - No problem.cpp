/*
Be careful with S being 0 (that got me)
*/
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int S;
    int months[12], problems[12], total;
    int i,j,caso=0;

    while(scanf("%d", &S) == 1 && S >= 0){
        printf("Case %d:\n", ++caso);
        for(i=0;i<12;i++){
            scanf("%d", &months[i]);
        }
        for(i=0;i<12;i++){
            scanf("%d", &problems[i]);
        }
        for(i=0;i<12;i++){
            total = S;
                for(j=i-1;j>=0;j--){
                    total += months[j];
                }
            if(problems[i] > total){
                printf("No problem. :(\n");
            }
            else{
                printf("No problem! :D\n");
                months[0] -=problems[i];
            }
        }
    }
    return 0;
}

