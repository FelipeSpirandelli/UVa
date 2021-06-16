´#include <bits/stdc++.h>
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

int N;
vi visited;
vector<vi> graph;

void dfs(int a){
    visited[a] = 1;

    rep(i,0,graph[a].size())
        if(visited[graph[a][i]] == 0)
            dfs(graph[a][i]);
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T, total;
    char in, en;
    string s;
    cin >> T;

    while(T--){
        cin >> in;
        N = in - 'A' + 1;
        graph.clear();
        visited.clear();
        total = 0;
        visited.resize(N, 0);
        graph.resize(N, vi());
        cin.ignore();
        while(getline(cin, s)){
            if(s.size() == 0)
                break;
            stringstream ss(s);
            ss >> in >> en;
            graph[in-'A'].pb(en - 'A');
            graph[en-'A'].pb(in - 'A');
        }
        rep(i,0,N){
            if(visited[i] == 0){
                dfs(i);
                total++;
            }

        }
        cout << total line;
        if(T)
            cout line;
    }


    return 0;
}

