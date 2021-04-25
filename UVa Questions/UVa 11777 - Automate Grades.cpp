#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

bool comp(int A, int B){
    return A > B;
}


int main(){
    ios_base::sync_with_stdio(false);

    int X;
    int T1, T2, F, A, CT[3];
    int caso = 0;
    float grade;
    char ch;
    string s;

    cin >> X;
    cin.ignore();
    while(X--){
        getline(cin, s);
        stringstream ss(s);
        ss >> T1 >> T2 >> F >> A >> CT[0] >> CT[1] >> CT[2];
        sort(CT, CT + 3, comp);
        grade = T1 + T2 + F + A + (CT[0] + CT[1])/2.0;
        if(grade >= 90 ) ch = 'A';
        else if(grade >= 80) ch = 'B';
        else if(grade >= 70) ch = 'C';
        else if(grade >=60) ch = 'D';
        else ch = 'F';
        cout << "Case " <<  ++caso << ": " << ch << endl;
    }

    return 0;
}

