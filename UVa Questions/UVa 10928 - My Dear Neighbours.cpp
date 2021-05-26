#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N, P, aux, minimum, i, j;
    vector<vi> neighbours;
    string s;
    vi best;

    cin >> N;
    while( N-- ){
        cin >> P;
        best.clear();
        neighbours.clear();
        neighbours.resize(P);
        cin.ignore();
        for(i = 0; i < P; i++){
            getline(cin, s);
            stringstream ss(s);
            while(ss >> aux){
                neighbours[i].push_back(aux);
            }
        }
        minimum = 10000;
        for(i = 0; i < P; i++){
            if(neighbours[i].size() < minimum){
                minimum = neighbours[i].size();
                best.clear();
                best.push_back(i+1);
            }
            else if (neighbours[i].size() == minimum){
                best.push_back(i+1);
            }
        }
        cout << best[0];
        for(i = 1; i < best.size(); i++){
            cout << " " << best[i];
        }
        cout << endl;
    }

    return 0;
}
