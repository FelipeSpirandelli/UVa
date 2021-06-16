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


int N, paci[1005];

int find_leader(int a)
{
    return paci[a] == -1 ? a : paci[a] = find_leader(paci[a]);
}

void add_member(int a, int b)
{

    paci[find_leader(b)] = find_leader(a);

}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int C, A, B, number;
    bool first = true;
    memset(paci, -1, sizeof paci);


    cin >> N >> C;

    rep(i,0,C)
    {
        cin >> A >> number;
        rep(j,0,number)
        {
            cin >> B;
            add_member(A, B);
        }
    }

    rep(i,1,N+1)
    {
        if(paci[i] == -1)
        {
            if(!first)
            {
                cout line;
            }
            else
                first = false;
            cout << i;

        }
    }


    return 0;
}
