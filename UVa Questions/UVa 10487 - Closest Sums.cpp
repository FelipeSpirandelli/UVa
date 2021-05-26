#include <bits/stdc++.h>
#define _  << " " <<
#define rep(i,a,b) for(int i = a; i < b; i++)
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
    int n, m, aux, best, sum, casecounter = 0;
    vi numbers;

    while(cin >> n && n){
        cout << "Case" _ ++casecounter << ":" << endl;
        numbers.clear();
        rep(i,0,n){
            cin >> aux;
            numbers.push_back(aux);
        }
        sort(numbers.begin(), numbers.end());
        cin >> m;
        rep(i,0,m){
            best = numbers[0] + numbers[1];
            cin >> aux;
            for(int low = 0; low < n - 1; low++){
                for(int high = low + 1; high < n; high++){
                    sum = numbers[low] + numbers[high];
                    if(abs(sum - aux) < abs(best - aux))
                        best = sum;
                }
            }
            cout << "Closest sum to" _ aux _ "is" _ best << "." << endl;
        }
    }
    return 0;
}
