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

int ilhas[1005][1005], dist[1005];
bool sptSet[1005];
int N, S;


int minDistance(){
    int MIN = INF, min_index;
    rep(i,0,N){
        if(sptSet[i] == false && dist[i] <= MIN){
            MIN = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(){
    rep(i,0,N-1){
        int u = minDistance();
        sptSet[u] = true;
        rep(j,0,N){
             if(sptSet[j] == false && ilhas[u][j] && dist[u] != INF
                && dist[j] > dist[u] + ilhas[u][j])
                    dist[j] = dist[u] + ilhas[u][j];
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int aux, ilha1, ilha2, M;
    int MIN, MAX;

    cin >> N >> M;

    rep(i,0,N){
        dist[i] = INF;
        sptSet[i] = false;
        rep(j,0,N){
            ilhas[i][j] = 0;
        }
    }

    rep(i,0,M){
        cin >> ilha1 >> ilha2 >> aux;
        ilha1--;ilha2--;
        ilhas[ilha1][ilha2] = aux;
        ilhas[ilha2][ilha1] = aux;
    }
    cin >> S;
    --S;
    dist[S] = 0;
    dijkstra();
    MIN = INF; MAX = -1;
    rep(i,0,N){
        if(i == S)
            continue;
        MAX = max(dist[i], MAX);
        MIN = min(dist[i], MIN);
    }
    cout << MAX - MIN;


    return 0;
}













