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

int  n;
vi rung;

bool possible(int k){
    if(rung[0] > k )                  
        return false;
    else if(rung[0] == k)
        k--;
    rep(i,0,rung.size()-1){
        if(rung[i+1] - rung[i] <k)
            continue;
        else if(rung[i+1] - rung[i] == k)
            k--;
        else
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int aux, T;
    int lo, hi, mid, ans, caseCounter = 0;

    cin >> T;
    while(T--){
        cin >> n;
        rung.clear();
        rep(i,0,n){
            cin >> aux;
            rung.pb(aux);
        }
        lo = 0; hi = 100000000;
        rep(i,0,100){
            mid = (lo+hi)/2;
            if(possible(mid)){
                ans = mid;
                hi = mid;
            }
            else
                lo = mid;
        }
        cout << "Case" _ ++caseCounter doisp _ ans line;
    }

    return 0;
}




