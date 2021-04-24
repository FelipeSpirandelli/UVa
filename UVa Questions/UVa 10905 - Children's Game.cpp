#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

bool comp(string A, string B){
    return A + B > B + A;
}

int main(){
    ios_base::sync_with_stdio(false);
    
    int N;
    int i;
    string auxNumber;
    string s;
    vector<string> numbers;

    while(cin >> N && N!=0){
        cin.ignore();
        numbers.clear();
        getline(cin, s);
        stringstream ss(s);
        rep(i,0,N){
            ss >> auxNumber;
            numbers.push_back(auxNumber);
        }
        sort(numbers.begin(), numbers.end(), comp);

        rep(i,0,N){
            cout << numbers[i];
        }
        cout << endl;
    }

    return 0;
}


