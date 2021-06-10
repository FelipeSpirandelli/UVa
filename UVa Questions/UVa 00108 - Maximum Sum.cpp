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
    int N, MAX, auxMAX;
    int box[101][101];


    cin >> N;
    rep(i,0,N){
        rep(j,0,N){
            cin >> box[i][j];
            if(i > 0) box[i][j] += box[i-1][j];
            if(j > 0) box[i][j] += box[i][j-1];
            if(i > 0 && j > 0) box[i][j] -= box[i-1][j-1];
        }
    }
    MAX = -INF;
    rep(i,0,N){
        rep(j,0,N){
            rep(k,i,N){
                rep(l,j,N){
                    auxMAX = box[k][l];
                    if(i > 0) auxMAX -= box[i-1][l];
                    if(j > 0) auxMAX -= box[k][j-1];
                    if(j > 0 && i > 0) auxMAX += box[i-1][j-1];
                    MAX = max(MAX, auxMAX);
                }
            }
        }
    }
    cout << MAX line;


    return 0;
}






