#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


struct person{
    string name;
    int day, month, year;

};

bool comp(struct person A, struct person B){
    if(A.year != B.year) return A.year > B.year;
    else if(A.month != B.month) return A.month > B.month;
    else return A.day > B.day;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);

    int P;
    int i;
    vector<struct person> people;
    struct person personAux;
    string s, name;

    cin >> P;
    cin.ignore();
    rep(i,0,P){
        getline(cin, s);
        stringstream ss(s);
        ss >> personAux.name >> personAux.day >> personAux.month >> personAux.year;
        people.push_back(personAux);
    }
    sort(people.begin(), people.end(), comp);
    cout << people[0].name << endl << people[people.size() - 1].name << endl;

    return 0;
}

