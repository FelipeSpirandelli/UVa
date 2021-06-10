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
    int N, x1,x2,y1,y2, aux;
    int bar[1005][1005];

    cin >> N >> x1 >> y1 >> x2 >> y2;
    aux = 0;
    memset(bar,0,sizeof(bar));
    bar[--x1][--y1]++;
    bar[--x2][--y2]++;

    rep(i,0,N)
    {
        rep(j,0,N/2)
        {
            if(bar[i][j] > 0)
                aux++;
        }
    }
    if(aux == 1)
        cout << "S" line;
    else
    {
        aux = 0;
        rep(i,0,N/2)
        {
            rep(j,0,N)
            {
                if(bar[i][j] > 0)
                    aux++;
            }
        }
        if(aux == 1)
            cout << "S" line;
        else
            cout << "N" line;
    }


    return 0;
}






