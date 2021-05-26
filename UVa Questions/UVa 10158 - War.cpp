#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;
vi people;

int fin(int a){
    return people[a] < 0 ? a : fin(people[a]);
}

void uni(int a, int b){
    if(fin(a) != fin(b)){
        if(people[fin(a)] <= people[fin(b)])
            people[fin(b)] = fin(a);
        else
            people[fin(a)] = fin(b);
    }
}

int enemyID(int a){
    return a + n;
}

bool belongs(int a, int b){
    return fin(a) == fin(b);
}

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int operation, first, second;
    string s;

    cin >> n;
    people.resize(2*n, -1);
    cin.ignore();
    while(getline(cin,s)){
        stringstream ss(s);
        ss >> operation >> first >> second;
        if(operation == 0)
            break;
        if(operation == 1){
            if(fin(first) == fin(enemyID(second)) || fin(enemyID(first)) == fin(second)){
                cout << -1 << endl;
            }
            else{
                uni(first, second);
                uni(enemyID(first), enemyID(second));
            }
        }
        else if (operation == 2){
            if(fin(first) == fin(second))
                cout << -1 << endl;
            else{
                uni(first, enemyID(second));
                uni(second, enemyID(first));
            }
        }
        else if(operation == 3){
            if(fin(first) == fin(second)){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(operation == 4){
            if(fin(first) == fin(enemyID(second)) ){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }


    return 0;
}
