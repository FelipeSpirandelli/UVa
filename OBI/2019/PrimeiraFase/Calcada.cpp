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
    int N, aux, MAX = 1, estado = 1;
    vi sequence;
    set<int> num;
    set<int>::iterator it, ite;

    cin >> N;

    rep(i,0,N){
        cin >> aux;
        num.emplace(aux);
        sequence.pb(aux);
    }
    for(it = num.begin(); it != num.end(); it++){
        for(ite = num.begin(); ite != num.end(); ite++){
            aux = 0;
            estado = 1;
            if(it == ite)
                continue;
            rep(i,0,N){
                switch(estado){
                case 1:
                    if(*it == sequence[i]){
                        aux++;
                        estado = 2;
                    }
                    break;
                case 2:
                    if(*ite == sequence[i]){
                        aux++;
                        estado = 1;
                    }
                    break;
                }
            }
            MAX = max(aux, MAX);
        }
    }

    cout << MAX;

    return 0;
}













