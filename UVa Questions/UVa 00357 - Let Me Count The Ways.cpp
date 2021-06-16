#include <bits/stdc++.h>
#define _  << " " <<
#define pb push_back
#define line << endl
#define doisp << ":"
#define rep(i,a,b) for(int i = a; i < b; i++)
#define EPS 1e-15
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
const int INF=0xfffffff;
const int mod=1e6;


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll dp[30005];
    int n, coins[] = {1, 5 ,10, 25, 50};

    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    rep(i,0,5){
        for(int j = coins[i]; j <= 30004; j++){
            dp[j] += dp[j - coins[i]];
        }
    }

    while(cin >> n){
        if(dp[n]!= 1)
            cout << "There are" _ dp[n] _ "ways to produce" _ n _ "cents change." line;
        else
            cout << "There is only" _ 1 _ "way to produce" _ n _ "cents change." line;
    }


    return 0;
}













