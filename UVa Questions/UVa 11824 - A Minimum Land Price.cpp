#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

bool comp(int A, int B){
    return A > B;
}

long long int power(int A, int B){
    int i;
    long long int total = 1;
    rep(i,0,B){
        total *= A;
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);

    int T;
    vector<int> prices;
    int auxPrice, i, flag;
    long long int total;

    cin >> T;
    cin.ignore();
    while(T--){
        prices.clear();
        total = 0;
        flag = 0;
        while(cin >> auxPrice && auxPrice > 0){
            cin.ignore();
            prices.push_back(auxPrice);
        }
        cin.ignore();
        sort(prices.begin(), prices.end(), comp);
        rep(i,0,prices.size()){
            total += 2 * power(prices[i], i+1);
            if(total > 5000000){
                flag++;
                break;
            }
        }
        if( total <= 5000000 && flag == 0) cout << total << endl;
        else cout << "Too expensive" << endl;
    }

    return 0;
}

