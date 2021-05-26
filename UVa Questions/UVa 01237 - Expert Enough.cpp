#include <bits/stdc++.h>
#define _  << " " <<
# define INF 0x3f3f3f3f3f
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T, D, Q, P, low, high, flag;
    string name;
    vector<string> names;
    vii prices;


    cin >> T;
    while(T--){
        cin >> D;
        prices.clear();
        names.clear();
        for(int i = 0; i < D; i++){
            cin >> name >> low >> high;
            names.push_back(name);
            prices.push_back(ii(low, high));
        }
        cin >> Q;
        while(Q--){
            flag = 0;
            cin >> P;
            for(int i = 0; i < D; i++){
                if(prices[i].first <= P && prices[i].second >= P){
                    flag++;
                    name = names[i];
                }
                if(flag > 1)
                    break;
            }
            if(flag != 1)
                cout << "UNDETERMINED" << endl;
            else if(flag == 1){
                cout << name << endl;
            }
        }
        if(T) cout << endl;
    }


    return 0;
}
