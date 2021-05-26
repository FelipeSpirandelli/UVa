#include <bits/stdc++.h>
#define _  << " " <<
# define INF 0x3f3f3f3f3f
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

long long int power(long long int a, int b){
    long long int total = 1;
    for(int i = 0; i < b; i++){
        total *= a;
    }
    return total;
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int C, d, k, degree;
    vi coefficients;
    string s;
    long long int result, aux;

    cin >> C;
    while(C--){
        cin >> degree; degree++;
        coefficients.clear();
        while(degree--){
            cin >> aux;
            coefficients.push_back(aux);
        }
        cin >> d >> k;
        for(aux = 1; d * aux*(aux+1)/2 < k; aux++){}
        result = 0;
        for(int i = 0; i < coefficients.size(); i++){
            result += coefficients[i] * power(aux,i);
        }
        cout << result << endl;
    }

    return 0;
}
