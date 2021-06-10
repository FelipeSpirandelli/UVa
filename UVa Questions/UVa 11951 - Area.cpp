//For some reason, it gets WA, but almost every test case is AC
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
    int T, N, M, line_counter = 0;
    ll K, ma[110][110], MAXarea, money, aux_money;

    cin >> T;
    while(T--){
        cin >> N >> M >> K;
        rep(i,0,N){
            rep(j,0,M){
                cin >> ma[i][j];
                if(i > 0) ma[i][j] += ma[i-1][j];
                if(j > 0) ma[i][j] += ma[i][j-1];
                if(i > 0 && j > 0) ma[i][j] -= ma[i-1][j-1];
            }
        }
        MAXarea = -INF;
        money = INF;
        rep(i,0,N){
            rep(j,0,M){
                rep(k,i,N){
                    rep(l,j,M){
                        aux_money = ma[k][l];
                        if(i > 0) aux_money -= ma[i-1][l];
                        if(j > 0) aux_money -= ma[k][j-1];
                        if( i > 0 && j > 0) aux_money += ma[i-1][j-1];
                        if(aux_money <= K){
                            if( (k-i+1)*(l-j+1) > MAXarea){
                                MAXarea = (k-i+1)*(l-j+1);
                                money = aux_money;
                            }
                            else if((k-i+1)*(l-j+1) == MAXarea ){
                                if(aux_money < money)
                                    money = aux_money;
                            }
                        }
                    }
                }
            }
        }
        cout << "Case" _ "#" << ++line_counter doisp _ MAXarea _ money line;
    }

    return 0;
}






