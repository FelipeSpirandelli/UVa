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

const int SIZE = 1005;

int N, MW, P[SIZE], W[SIZE], dp[SIZE][31];

int solve(int item, int wei){
    if(dp[item][wei] != -1)
        return dp[item][wei];
    if(wei == 0)
        return 0;
    if( item == N)
        return 0;
    if(W[item] > wei)
        return dp[item][wei] = solve(item + 1, wei);
    else
        return dp[item][wei] = max(solve(item + 1, wei), P[item] + solve(item + 1, wei - W[item]));
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T,G, aux, total;

    cin >> T;
    while(T--){
        total = 0;
        memset(dp, -1, sizeof dp);
        cin >> N ;
        rep(i,0,N){
            cin >> P[i] >> W[i];
        }
        cin >> G;
        rep(i,0,G){
            cin >> MW;
            total += solve(0, MW);
        }
        cout << total line;

    }

    return 0;
}













