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
const int mod=1e9 + 7;

int m, S, dp[303][303][42];
pair<int, int> coins[42];

int emod(int conv, int tech){
    return conv * conv + tech * tech;
}

int solve(int conv, int tech, int pos){
    int value = emod(conv, tech);
    if(S - value <= 0){
        return value == S ? 0 : INF;
    }
    if(pos == m)
        return INF;
    if(dp[conv][tech][pos] != -1)
        return dp[conv][tech][pos];

    dp[conv][tech][pos] = min(solve(conv + coins[pos].first, tech + coins[pos].second, pos ) + 1,  solve(conv, tech, pos + 1));

    return dp[conv][tech][pos];
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;

    cin >> n;
    while(n--){
        cin >> m >> S;
        S = S * S;
        rep(i,0,m){
            cin >> coins[i].first >> coins[i].second;
        }
        memset(dp, -1, sizeof dp);
        int total = solve(0,0,0);
        if(total != INF)
            cout << total line;
        else
            cout << "not possible" line;
    }



    return 0;
}













