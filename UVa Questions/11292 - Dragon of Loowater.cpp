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
const int INF=0xfffffff;
const int mod=1e9+7;



int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    int aux, total;
    vi head, kni;

    while(cin >> n >> m && n && m){
        head.clear();
        kni.clear();
        rep(i,0,n){
            cin >> aux;
            head.pb(aux);
        }
        rep(i,0,m){
            cin >> aux;
            kni.pb(aux);
        }
        sort(head.begin(),head.end());
        sort(kni.begin(), kni.end());
        total = 0;
        int i,j;
        for(i = 0, j = 0; i < n && j < m;j++){
            if(kni[j] >= head[i]){
                total+= kni[j];
                i++;
            }
        }
        if(i == n){
            cout << total line;
        }
        else
            cout << "Loowater is doomed!" line;


    }

    return 0;
}




