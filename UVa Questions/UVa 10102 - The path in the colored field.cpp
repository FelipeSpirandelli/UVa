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
    int M, aux, maximum, minimum, distance;
    string s;
    int field[100][100];

    while(cin >> M){
        cin.ignore();
        rep(i,0,M){
            getline(cin, s);
            rep(j,0,M){
               field[i][j] = s[j] - '0';
            }
        }
        maximum = 0;
        minimum = 0;
        rep(i,0,M){
            rep(j,0,M){
                if(field[i][j] == 1){
                    minimum = 10000;
                    rep(k,0,M){
                        rep(l,0,M){
                            if(field[k][l] == 3){
                                distance = abs(i - k) + abs(j - l);
                                if(distance < minimum)
                                    minimum = distance;
                            }
                        }
                    }
                }
                if(minimum > maximum)
                    maximum = minimum;
            }
        }
        cout << maximum << endl;
    }


    return 0;
}
