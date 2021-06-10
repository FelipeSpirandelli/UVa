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


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, d, r, aux, total;
    vi mor, aft;

    while(cin >> n >> d >> r && n){
        mor.clear(); aft.clear();
        rep(i,0,n){
            cin >> aux;
            mor.pb(aux);
        }
        rep(i,0,n){
            cin >> aux;
            aft.pb(aux);
        }
        sort(mor.begin(), mor.end());
        sort(aft.begin(), aft.end());
        total = 0;
        rep(i,0,n){
            if(mor[i] + aft[n-1-i] - d > 0)
                total += r * (mor[i] + aft[n-1-i] - d);
        }
        cout << total line;
    }


    return 0;
}






