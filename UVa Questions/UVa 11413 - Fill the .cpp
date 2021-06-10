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
const int INF=0xfffffff;
const int mod=1e9+7;

int n, m;
vi capacity;

bool valid(int liters){
    int cont[m];
    rep(i,0,m)
        cont[i] = liters;
    int i,j;
    for(i = 0, j = 0; i < n; i++){
        if(capacity[i] > liters)
            return false;
        if(cont[j] < capacity[i]){
            j++;
            if(j == m)
                return false;
            cont[j] -= capacity[i];
        }
        else
            cont[j] -= capacity[i];
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int aux, lo, hi, mid, ans;

    while(cin >> n >> m){
        capacity.clear();
        rep(i,0,n){
            cin >> aux;
            capacity.pb(aux);
        }
        lo = 0; hi = 1000000000;
        rep(i,0,100){
            mid = (lo+hi)/2;
            if(valid(mid)){
                ans = mid;
                hi = mid;
            }
            else
                lo = mid;
        }
        cout << ans line;
    }

    return 0;
}




