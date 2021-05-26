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

    bool valid;
    int t, i, j, aux, flag, total;
    int n,m;
    vector<vi> matrix;
    vector<vi> edges;
    string s;

    cin >> t;
    while(t--){
        valid = true;
        total = 0;
        cin >> n >> m;
        matrix.clear();
        edges.clear();
        matrix.resize(n);
        edges.resize(m);
        cin.ignore();
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                cin >> aux;
                matrix[i].push_back(aux);
            }
        }
        //validation
        for(i = 0; i < m; i++){
            flag = 0;
            for(j = 0; j < n; j++){
                if(matrix[j][i] == 1){
                    flag++;
                    edges[i].push_back(j);
                }
            }
            if(flag != 2)
                valid = false;
        }
        for(i = 0; i < m - 1; i++){
            for(j = i+1; j < m ; j++){
                if(edges[i][0] == edges[j][0]){
                    if(edges[i][1] == edges[j][1]){
                        valid = false;
                    }
                }
                if(valid == false)
                    break;
            }
            if(valid == false)
                break;
        }
        if(valid == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
