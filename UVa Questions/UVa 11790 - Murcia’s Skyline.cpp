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

const int SIZE = 10000;

int n;
int hei[SIZE], width[SIZE];

int lis[SIZE], lds[SIZE];

int LIS(int a){
    if(lis[a] != -1)
        return lis[a];
    int aux = 0, MAX = width[a];
    rep(i,a,n){
        if(hei[i] > hei[a]){
            aux = LIS(i);
            MAX = max(aux + width[a], MAX);
        }
    }
    return lis[a] = MAX;

}

int LDS(int a){
    if(lds[a] != -1)
        return lds[a];
    int aux = 0, MAX = width[a];
    rep(i,a,n){
        if(hei[i] < hei[a]){
            aux = LDS(i);
            MAX = max(aux + width[a], MAX);
        }
    }
    return lds[a] = MAX;
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, mx_lis, mx_lds, case_counter = 0;

    cin >> t;

    while(t--){
        cin >> n;
        memset(lis, -1, sizeof lis);
        memset(lds, -1, sizeof lds);
        rep(i,0,n){
            cin >> hei[i];
        }
        rep(i,0,n){
            cin >> width[i];
        }
        lis[n-1] = width[n-1];
        lds[n-1] = width[n-1];
        mx_lis = 0, mx_lds = 0;
        rep(i,0,n){
            mx_lis = max(mx_lis, LIS(i));
            mx_lds = max(mx_lds, LDS(i));
        }
        if(mx_lis >= mx_lds)
            cout << "Case" _ ++case_counter << "." _ "Increasing (" << mx_lis << ")." _ "Decreasing (" << mx_lds << ")." line;
        else
            cout << "Case" _ ++case_counter << "." _ "Decreasing (" << mx_lds << ")." _ "Increasing (" << mx_lis << ")." line;
    }

    return 0;
}













