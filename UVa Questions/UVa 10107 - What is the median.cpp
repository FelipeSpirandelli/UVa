#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);

    int auxNumber, Total = 0, auxTotal;
    vector<int> numbers;
    bool isEven = true;

    while(cin >> auxNumber){
        Total++;
        isEven = !isEven;
        numbers.push_back(auxNumber);
        sort(numbers.begin(), numbers.end());
        if(isEven){
            auxTotal = Total - ((Total & 1) ^ 1);
            cout << (numbers[auxTotal/2] + numbers[auxTotal/2 + 1])/2 << endl;
        }
        else{
            auxTotal = Total;
            cout << numbers[auxTotal/2] << endl;
        }
    }
    return 0;
}

