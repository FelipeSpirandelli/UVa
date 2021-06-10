#include <bits/stdc++.h>
#define _  << " " <<
#define pb push_back
#define line << endl
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF=0xfffffff;
const int mod=1e9+7;

int prime[11] = {2,3,5,7,11,13,17,19,23,29,31};
int numbers[16] = {0};
int N;
vi circle;

bool isPrime(int a){
    rep(i,0,11)
        if(prime[i] == a)
            return true;

    return false;
}

bool isValid(int position){
    rep(i,0,position){
        if(i == N-1){
            if(!isPrime(circle[0] + circle[i]))
                return false;
        }
        else if(!isPrime(circle[i] + circle[i+1]))
            return false;
    }
    return true;
}

void solve(int position){
    if(position == N){
        if(isValid(position)){
            cout << circle[0];
            rep(i,1,N)
                cout << " " << circle[i];
            cout << endl;
        }
        return;
    }
    if(!isValid(position-1))
        return;
    rep(i,0,N){
        if(numbers[i] == 0){
            circle.pb(i+1);
            numbers[i] = 1;
            solve(position+1);
            numbers[i] = 0;
            circle.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int counter = 0;
    while(cin >> N){
        if(counter != 0)
            cout << endl;
        numbers[0] = 1;
        circle.push_back(1);
        cout << "Case" _ ++counter << ":" << endl;
        solve(1);
        circle.pop_back();
    }


    return 0;
}


