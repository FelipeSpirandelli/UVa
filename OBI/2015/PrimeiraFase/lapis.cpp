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
    int N;
    int mat[1005][1005];
    char aux;
    vii zeros;


    cin >> N;
    rep(i,0,N){
        rep(j,0,N){
            mat[i][j] = 9;;
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            cin >> aux;
            if(aux - '0' == 0)
                zeros.pb(make_pair(i,j));
        }
    }

    rep(k,0,zeros.size()){
        rep(i, zeros[k].first - 9, zeros[k].first + 9){
            rep(j,zeros[k].second - 9, zeros[k].second + 9)
                if(i >= 0 && i < N && j >=0 && j <= N){
                    int distance = abs(i - zeros[k].first) + abs(j - zeros[k].second);
                    if(distance > 9)
                        mat[i][j] = min( 9, mat[i][j]);
                    else
                        mat[i][j] = min( distance, mat[i][j]);
                }
        }

    }
    rep(i,0,N){
        rep(j,0,N){
            cout << mat[i][j];
        }
        cout line;
    }

    return 0;
}













