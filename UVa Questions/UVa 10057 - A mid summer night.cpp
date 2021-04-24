#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);

    int n;
    int auxNumber, i, auxN, repetion;
    vector<int> numbers;


    while(cin >> n){
        repetion = 0;
        numbers.clear();
        rep(i,0,n){
            cin >> auxNumber;
            numbers.push_back(auxNumber);
        }
        sort(numbers.begin(), numbers.end());
        if(!(n&1)){
            auxN = n - 1;
            rep(i,0,n){
                if(numbers[i] == numbers[auxN/2] || numbers[i] == numbers[auxN/2 + 1]){
                    repetion++;
                }
            }
            cout << numbers[auxN/2] << " " << repetion << " " << numbers[auxN/2+1] - numbers[auxN/2] + 1<< endl;
        }
        else{
            rep(i,0,n){
                if(numbers[i] == numbers[n/2]){
                    repetion++;
                }
            }
            cout << numbers[n/2] << " " << repetion << " " << "1" << endl;
        }

    }

    return 0;
}

