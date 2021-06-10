#include <bits/stdc++.h>
#define _  << " " <<
#define pb push_back
#define line << endl
#define rep(i,a,b) for(int i = a; i < b; i++)
#define EPS 1e-9
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF=0xfffffff;
const int mod=1e9+7;


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Y, P, aux, size_now, best, lo, hi;
    vi years;

    while(cin >> Y){
        years.clear();
        cin >> P;
        rep(i,0,P){
            cin >> aux;
            years.pb(aux);
        }
        best = 0;
        rep(i,0,P){
            size_now = upper_bound(years.begin() + i + 1, years.end(), years[i] + Y - 1) - (years.begin() + i + 1);

            if(size_now +1> best){
                best = size_now+1;
                lo = years[i];
                hi = years[i+size_now];
            }
        }
        cout << best _ lo _ hi line;
    }

    return 0;
}




