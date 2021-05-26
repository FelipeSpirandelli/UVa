#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi computers;

int fin(int a){
    return computers[a] < 0 ? a : fin(computers[a]);
}

void uni(int a, int b){
    if(fin(a) != fin(b) ){
        if(computers[fin(a)] <= computers[fin(b)])
            computers[fin(b)] = fin(a);
        else
            computers[fin(a)] = fin(b);
    }
}

bool connected(int a, int b){
    if(fin(a) == fin(b))
        return true;
    else
        return false;

}

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t, n, first, second;
    int success, failure = -1;
    char func;
    string s;

    cin >> t;
    while(t--){
        if(failure != -1)
            cout << endl;
        cin >> n;
        computers.clear();
        computers.resize(n, -1);
        success = 0;
        failure = 0;
        cin.ignore();
        while(true){
            if( !getline(cin, s) || s.empty()) break;
            stringstream ss(s);
            ss >> func >> first >> second;
            if(func == 'c'){
                uni(first-1, second-1);
            }
            else{
                if(connected(first-1, second-1))
                    success++;
                else
                    failure++;
            }
        }
        cout << success << "," << failure << endl;
    }

    return 0;
}
