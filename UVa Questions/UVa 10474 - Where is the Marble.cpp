#include <bits/stdc++.h>
#define _  << " " <<
#define pb push_back
#define line << endl
#define doisp << ":"
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
    int N, Q;
    int aux, querry, position, case_counter = 0;
    vi marbles;
    while(cin >> N >> Q && N && Q){
        marbles.clear();
        cout <<  "CASE#" _ ++case_counter doisp line;
        rep(i,0,N){
            cin >> aux;
            marbles.pb(aux);
        }
        sort(marbles.begin(), marbles.end());
        rep(i,0,Q){
            cin >> querry;
            position = find(marbles.begin(), marbles.end(), querry) - marbles.begin();
            if(position == N )
                cout << querry _ "not found" line;
            else
                cout << querry _ "found at" _ position +1 line;
        }

    }

    return 0;
}




