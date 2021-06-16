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

const int SIZE = 205;

ll d, m, n, num[SIZE];

ll sums[SIZE][21][15];

ll subSum(int put, int sum, int a){
    if(put == m && sum%d == 0)
        return sums[a][sum][put] = 1;
    if(put == m && sum%d != 0)
        return sums[a][sum][put] = 0;
    if(a == n){
        return sums[a][sum][put] = 0;
    }
    if(sums[a][sum][put] != -1)
        return sums[a][sum][put];
    return sums[a][sum][put] = subSum(put, sum, a+1) + subSum(put+1, ((sum + num[a]) % d + d)%d, a+1);
}



int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q, test_counter = 0, query_counter;

    while(cin >> n >> q && n){
        query_counter = 0;
        cout << "SET" _ ++test_counter doisp line;
        rep(i,0,n){
            cin >> num[i];
        }
        rep(i,0,q){
            cin >> d >> m;
            memset(sums, -1, sizeof sums);
            cout << "QUERY" _ ++query_counter doisp _ subSum(0, 0, 0) line;
        }
    }


    return 0;
}













