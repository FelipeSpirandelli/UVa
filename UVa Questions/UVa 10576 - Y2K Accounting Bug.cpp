#include <bits/stdc++.h>
#define _  << " " <<
#define pb push_back
#define line << endl
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF=0xfffffff;
const int mod=1e9+7;

int s, d, MAX;
vi year, best_year;

void solve(int month, int sum){
    if(month == 12){
        rep(i,4,12){
            if(year[i] + year[i-1] + year[i-2] + year[i-3] + year[i-4] > 0){
                return;
            }
        }
        if(sum > MAX ){
            MAX = sum;
            best_year = year;
        }
        return;
    }

    year.pb(s);
    solve(month+1, sum + s);
    year.pop_back();
    year.pb(-d);
    solve(month+1, sum - d);
    year.pop_back();

}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while( cin >> s >> d){
        year.clear();
        MAX = 0;
        solve(0, 0);
        if(MAX > 0)
            cout << MAX line;
        else
            cout << "Deficit" line;
    }

    return 0;
}
