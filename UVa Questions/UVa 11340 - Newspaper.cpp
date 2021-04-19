/* 
The UVa judge decided to throw some non- ASCII characters just to 
mess with us. Therefore, you have to make the mask size 256 (account 
for negative characters). And when reading the input, sum 128.    
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, M;
    char ch;
    int cents, total;

    scanf("%d", &N);

    while(N--){
        int masks[256] = {};
        total = 0;
        scanf("%d", &K);
        while(K--){
            scanf(" %c %d", &ch, &cents);
            masks[ch + 128] = cents;
        }
        scanf("%d%*c", &M);
        while(M--){
            while(scanf("%c", &ch) && ch !='\n'){
                total += masks[ch + 128];
            }
        }
        printf("%d.%02d$\n", total/100, total%100);
    }
    
    return 0;
}

