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
    int t, N, aux, MAX;
    int ma[160][160];
    int sum[160][160];

    cin >> t;
    while(t--){
        cin >> N;
        rep(i,0,N){
            rep(j,0,N){
                cin >> ma[i][j];
                ma[i+N][j] = ma[i][j+N] = ma[i+N][j+N] = ma[i][j];
                if(i>0) sum[i][j]+= sum[i-1][j];
                if(j>0) sum[i][j] += sum[i][j-1];
                if(i > 0 && j > 0) sum[i][j]-= sum [i-1][j-1];
            }
        }
        rep(i,0,2*N){
            rep(j,0,2*N){
                sum[i][j] = ma[i][j];
                if(i>0) sum[i][j]+= sum[i-1][j];
                if(j>0) sum[i][j] += sum[i][j-1];
                if(i > 0 && j > 0) sum[i][j]-= sum [i-1][j-1];
            }
        }
        MAX = -INF;
        rep(i,0,N){
            rep(j,0,N){
                rep(k,i,i+N){
                    rep(l,j,j+N){
                        aux = sum[k][l];
                        if(i>0) aux -= sum[i-1][l];
                        if(j>0) aux -= sum[k][j-1];
                        if(i>0 && j>0) aux += sum[i-1][j-1];
                        MAX = max(MAX, aux);
                    }
                }
            }
        }
        cout << MAX line;
    }

    return 0;
}






