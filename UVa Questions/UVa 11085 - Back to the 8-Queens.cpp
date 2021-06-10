#include <bits/stdc++.h>
#define _  << " " <<
#define pb push_back
#define line << endl
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF=0xfffffff;
const int mod=1e9+7;

int rows[8], MIN;
vi position, best_position;

bool isAtacking(int column){
    rep(i,0,column-1)
        rep(j,i+1,column)
            if(position[i] == position[j] || abs(position[i] - position[j]) == abs(i - j))
                return true;
    return false;
}

void solve(int column, int moves){
    if(column == 8){
        if(isAtacking(column))
           return;
        if(moves < MIN){
            MIN = moves;
            best_position = position;
        }
        return;
    }
    if(isAtacking(column))
        return;
    for(int i = 1; i < 9; i++){
        position.pb(i);
        if(i == rows[column])
            solve(column + 1, moves);
        else
            solve(column+1, moves+1);
        position.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    int aux, i, counter = 0;
    while(getline(cin, s)){
        stringstream ss(s);
        i = 0;
        while(ss){
            ss >> aux;
            rows[i] = aux;
            i++;
        }
        MIN = INF;
        solve(0,0);
        cout << "Case" _ ++counter << ":" _ MIN line;
    }

    return 0;
}


