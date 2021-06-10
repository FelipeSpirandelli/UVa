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

map<int, int> members;

int count_gen(int a, int gen){
    if(members.find(a) == members.end())
        return 0;
    if(members.find(members[a]) != members.end()){
        gen = count_gen(members[a], gen) + 1;
    }
    return gen;
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N, M, fa, mem_foi;
    int gen[10000], foi[10000];

    memset(gen, 0, sizeof(gen));
    memset(foi, 0, sizeof(foi));
    cin >> N >> M;

    rep(i,1,N+1){
        cin >> fa;
        members[i] = fa;
    }
    rep(i,1,N+1){
        gen[count_gen(i,1)]++;
    }
    rep(i,0,M){
        cin >> mem_foi;
        foi[count_gen(mem_foi,1)]++;
    }
    cout << fixed << setprecision(2) << (foi[1] * 100.00)/gen[1];
    rep(i,2,N){
        if(gen[i] == 0)
            break;
        else{
            cout << fixed << setprecision(2) << " " << (foi[i] * 100.00)/gen[i];
        }
    }
    cout line;

    return 0;
}






