//Nothing special, just be careful on the extremes

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    int i;

    while(scanf("%d", &N) && N!=0){
        int samples[10001];
        for(i=0;i<N;i++){
            scanf("%d", &samples[i]);
        }
        int peak = 0;
        int l = i;
        if((samples[0] < samples[l-1] && samples[0] < samples[1]) || (samples[0] > samples[1] && samples[0] > samples[l-1])) peak++;
        if((samples[l-1] < samples[l-2] && samples[l-1] < samples[0]) || (samples[l-1] > samples[l-2] && samples[l-1] > samples[0])) peak++;
        for(i=1;i<l-1;i++){
             if((samples[i] < samples[i-1] && samples[i] < samples[i+1]) || (samples[i] > samples[i-1] && samples[i] > samples[i+1])) peak++;
        }
        printf("%d\n", peak);
    }

    return 0;
}

