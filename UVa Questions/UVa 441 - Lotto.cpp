#include <bits/stdc++.h>
#define _  << " " <<
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

    int n, aux, a, b, c, d, e = -100, f;
    vi numbers;
    string s;

    while(getline(cin,s) && s.size() > 5){
        if(e != -100)
            cout << endl;
        numbers.clear();
        stringstream ss(s);
        ss >> n;
        numbers.resize(n);
        for(int i = 0; i < n; i++){
            ss >> aux;
            numbers[i] = aux;
        }
        for(a= 0; a < n; a++){
            for(b= a+1; b < n; b++){
                for(c= b+1; c < n; c++){
                    for(d= c+1; d < n; d++){
                        for(e= d+1; e < n; e++){
                            for(f= e+1; f < n; f++){
                                cout << numbers[a] _ numbers[b] _ numbers[c] _ numbers[d] _ numbers[e] _ numbers[f] << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
