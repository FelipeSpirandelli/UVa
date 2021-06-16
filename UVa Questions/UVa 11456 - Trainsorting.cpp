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
typedef long long int ll;
const int INF=0xfffffff;
const int mod=1e6;

const int SIZE = 2005;

int n, cars[SIZE], inc[SIZE], decr[SIZE];

int LIS(int a){
    int aux, MAX = 1;
    if(a == n)
        return inc[n] = 1;
    if(inc[a] != -1)
        return inc[a];
    for(int i = a; i < n; i++){
        if(cars[i] > cars[a]){
            aux = 1 + LIS(i);
            MAX = max(aux, MAX);
        }
    }
    return inc[a] = MAX;
}

int LDS(int a){
    int aux, MAX = 1;
    if(a == n)
        return decr[n] = 1;
    if(decr[a] != -1)
        return decr[a];
    for(int i = a; i< n; i++){
        if(cars[i] < cars[a]){
            aux = 1 + LDS(i);
            MAX = max(aux, MAX);
        }
    }
    return decr[a] = MAX;
}

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, MAX;

    cin >> t;
    while(t--){
        cin >> n;
        memset(inc, -1, sizeof inc);
        memset(decr, -1, sizeof decr);
        MAX = 0;
        rep(i,0,n){
            cin >> cars[i];
        }
        rep(i,0,n){
            MAX = max(MAX, LIS(i) + LDS(i) - 1);
        }
        cout << MAX line;
    }

    return 0;
}













