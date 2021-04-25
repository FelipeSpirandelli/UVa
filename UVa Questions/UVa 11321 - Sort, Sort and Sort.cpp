#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

int M;

bool comp(int A, int B){
    if(A%M != B%M) return A%M < B%M;
    else{
        if(A%2==0 && B%2 == 0){
            return A < B;
        }
        else if(A%2!=0 && B%2 != 0){
            return A > B;
        }
        else if(A%2==0 && B%2 != 0){
            return false;
        }
        else if(A%2!=0 && B%2 == 0){
            return true;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    int N;
    int i;
    int auxNumber;
    string s;
    vector<int> numbers;

    getline(cin,s);
    stringstream ss(s);
    ss >> N >> M;
    while(N){
        numbers.clear();
        rep(i,0,N){
            cin >> auxNumber;
            cin.ignore();
            numbers.push_back(auxNumber);
        }
        sort(numbers.begin(), numbers.end(), comp);
        cout << N << " " << M << endl;
        rep(i,0,N){
            cout << numbers[i] << endl;
        }
        getline(cin,s);
        stringstream ss(s);
        ss >> N >> M;
        if(N == 0 && M == 0) cout << N << " " << M << endl;
    }

    return 0;
}

