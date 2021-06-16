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

vector<vi> graph;
int visited[105];

void dfs(int a, int b){
    if(a == b)
        return;
    visited[a] = 1;

    rep(i,0,graph[a].size()){
        if(visited[graph[a][i]] == 0)
            dfs(graph[a][i], b);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T, N, aux, case_counter = 0;
    int possible[105];

    cin >> T;
    while(T--){
        cin >> N;
        cout << "Case" _ ++case_counter doisp line;
        graph.clear();
        graph.resize(N, vi());
        rep(i,0,N){
            rep(j,0,N){
                cin >> aux;
                if(aux == 1)
                    graph[i].pb(j);
            }
        }
        memset(visited, 0, sizeof visited);
        dfs(0,-1);
        rep(i,0,N){
            possible[i] = visited[i];
        }
        cout << "+";
        rep(i,0,2*N-1)
            cout << "-";
        cout << "+\n";
        rep(i,0,N){
            memset(visited, 0, sizeof visited);
            dfs(0,i);
            rep(j,0,N){
                if(visited[j] == 0 && possible[j])
                    cout << "|Y";
                else
                    cout <<  "|N";

            }
            cout << "|\n";
            cout << "+";
            rep(j,0,2*N-1)
                cout << "-";
            cout << "+\n";
        }

    }


    return 0;
}













