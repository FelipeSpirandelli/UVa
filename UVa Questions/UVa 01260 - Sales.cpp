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
    int T, n, aux, sum, fixed;
    vi numbers;

    cin >> T;
    while(T--){
        cin >> n;
        sum = 0;
        numbers.clear();
        rep(i,0,n){
            cin >> aux;
            numbers.push_back(aux);
        }
        for(int i = 0; i < n; i++){
            fixed = numbers[i];
            for(int j = i - 1; j >=0;j--){
                if(fixed >= numbers[j])
                    sum++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
