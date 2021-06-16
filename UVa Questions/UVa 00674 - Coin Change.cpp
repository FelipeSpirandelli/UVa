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
    ll dp[7500];
    int n, coin[] = {1, 5, 10, 25, 50};

    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    rep(i,0,5){
        rep(j,coin[i], 7490){
            dp[j] += dp[j - coin[i]];
        }
    }
    while(cin >> n){
        cout << dp[n] line;
    }

    return 0;
}













