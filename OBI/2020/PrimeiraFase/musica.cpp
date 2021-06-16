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



int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, M, C, A, D, total;
    bool flag;
    map<int,vi> mus;
    map<int, vi>::iterator it;

    cin >> N >> M >> C;

    rep(i,0,N){
        cin >> A >> D;
        it = mus.find(D);
        if(it == mus.end()){
            vi a = { A };
            mus[D] = a;

        }
        else
            it->second.pb(A);
    }
    total = 0;
    flag = true;
    while(( it = mus.find(C) ) != mus.end()){

        C = it->second[0];
        total++;
        if(total > 100000){
            flag = false;
            break;
        }
    }
    if(flag)
        cout << total;
    else
        cout << -1;

    return 0;
}


