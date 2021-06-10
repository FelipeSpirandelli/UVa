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
const int mod=1e6;


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, sum, best, aux;


    while(cin >> N && N){
        best = 0;
        sum = 0;
        rep(i,0,N){
            cin >> aux;
            if(aux > 0){
                sum += aux;
                best = max(sum,best);
            }
            else{
                sum += aux;
                if(sum < 0)
                    sum = 0;
            }
        }
        best = max(sum,best);
        if(best <= 0)
            cout << "Losing streak." line;
        else
        cout << "The maximum winning streak is" _ best  << "." line;

    }


    return 0;
}






