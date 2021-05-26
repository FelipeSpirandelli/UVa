#include <bits/stdc++.h>
#define _  << " " <<
# define INF 0x3f3f3f3f3f
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int A,B,C, flag;
    int N, i, j, k;

    cin >> N;
    while(N--){
        cin >> A >> B >> C;
        for(i = -100;i <= 100; i++){
            for(j = -100; j <= 100; j++){
                for(k = -100; k <=100; k++){
                    flag = 0;
                    if(i == j || i == k || j ==k){
                        flag++;
                        continue;
                    }
                    else if(i + k + j != A){
                        flag++;
                        continue;
                    }
                    else if(i*k*j != B){
                        flag++;
                        continue;
                    }
                    else if(i*i + k*k + j*j != C){
                        flag++;
                        continue;
                    }
                    else{
                        cout << i _ j _ k << endl;
                        flag--;
                        break;
                    }
                }
                if(flag < 0)
                    break;
            }
            if(flag < 0)
                break;
        }
        if(flag > 0)
            cout << "No solution." << endl;
    }



    return 0;
}
