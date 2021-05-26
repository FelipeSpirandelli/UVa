#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi people;

int fin(int a){
    return people[a] < 0 ? a : people[a] = fin(people[a]);
}

void uni(int a, int b){
    if(fin(a) != fin(b)){
        if(people[fin(a)] <= people[fin(b)]){
            people[fin(a)] += people[fin(b)];
            people[fin(b)] = fin(a);
        }
        else{
            people[fin(b)] += people[fin(a)];
            people[fin(a)] = fin(b);
        }
    }
}

bool belong(int a, int b){
    return fin(a) == fin(b);
}

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t, P = -100, T, person, tree, number;
    int i, j;
    vector< set<int> > trees_heard;
    string s;

    cin >> t;
    cin.ignore();
    while(t--){
        if(P != -100)
            cout << endl;
        cin >> P >> T;
        trees_heard.clear();
        people.clear();
        trees_heard.resize(P, set<int>());
        people.resize(P, -1);
        getline(cin,s);
        while(getline(cin, s) && s.size() > 0){
            stringstream ss(s);
            ss >> person >> tree;
            trees_heard[person-1].insert(tree);
        }
        for(i = 0; i < P-1; i++){
            for(j = i+1; j < P; j++){
                if(trees_heard[i] == trees_heard[j]){
                    uni(i,j);
                }
            }
        }
        number = 0;
        for(i = 0; i < P; i++){
            if(people[i] <= -1){
                number++;
            }
        }
        cout << number << endl;
    }


    return 0;
}
