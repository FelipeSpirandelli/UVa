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
    long long int k, y;
    double fraction;
    int solcounter;

    while(cin >> k){
        solcounter = 0;
        for(y = k+1; y <= 2*k; y++){
            fraction = (k*y*1.0)/(y-k);
            if(fraction - (int)fraction == 0)
                solcounter++;
        }
        cout << solcounter << endl;
        for(y = k+1; y <= 2*k; y++){
            fraction = (k*y*1.0)/(y-k);
            if(fraction - (int)fraction == 0)
                cout << "1/" << k _ "=" _ "1/" << (k*y)/(y-k) _ "+ 1/" << y << endl;
        }
    }

    return 0;
}
