#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);

    int t;
    long int C, R;
    int caso = 0, i;
    string s;
    vector<int> G;

    cin >> t;
    cin.ignore();
    while(t--){
        G.clear();
        getline(cin, s);
        stringstream ss(s);
        ss >> C >> R;
        //Q*G + R = C => G = (C - R)/Q -> find divisors of C-R
        for(i=1;i*i <= C - R ; i++){
            if((C-R)%i == 0){
                if(i > R)G.push_back(i);
                if((C-R)/i > R && (C-R)/i != i)G.push_back((C-R)/i);
            }
        }
        sort(G.begin(), G.end());
        if(C != R){
            cout << "Case #" << ++caso << ":";
            rep(i,0,G.size()){
                cout << " " << G[i];
            }
            cout << endl;
        }
        else{
            cout << "Case #" << ++caso << ": 0";
            cout << endl;
        }
    }

    return 0;
}

