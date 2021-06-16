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



int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, M, total = 0;
    char L, contrario;
    multiset<ii> botas;

    cin >> N;

    while(N--){
        cin >> M;
        cin >> L;
        if(L == 'E')
            contrario = 'D';
        else
            contrario = 'E';
        auto itr = botas.find(make_pair(M,contrario));
        if(itr != botas.end()){
            botas.erase(itr);
            total++;
        }
        else{
            botas.emplace(make_pair(M,L));
        }
    }

    cout << total;

    return 0;
}













