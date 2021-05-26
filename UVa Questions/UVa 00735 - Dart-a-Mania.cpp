#include <bits/stdc++.h>
#define _  << " " <<
#define rep(i,a,b) for(int i = a; i < b; i++)
# define INF 0x3f3f3f3f3f
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int next_number(int a){
    switch(a){
        case 42: case 45: case 51: case 54: case 57:
            return a + 3;
        case 22: case 24: case 28: case 30: case 34: case 36: case 40: case 48:
            return a + 2;
        case 60:
            return -1;
        default:
            return a + 1;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int points, permutations, combinations;

    while(cin >> points && points > 0){
        permutations = 0;
        combinations = 0;
        for(int i = 0;;){
            for(int j = 0;;){
                for(int k = 0;;){
                    if(i + k + j == points){
                        permutations++;
                        if(k >= j && j >= i)
                            combinations++;
                    }
                    k = next_number(k);
                    if(k == -1)
                        break;
                }
                j = next_number(j);
                    if(j == -1)
                        break;
            }
            i = next_number(i);
                if(i == -1)
                    break;
        }
        if(combinations > 0){
            cout << "NUMBER OF COMBINATIONS THAT SCORES" _ points _ "IS" _ combinations << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES" _ points _ "IS" _ permutations << "." << endl;
        }
        else{
            cout << "THE SCORE OF" _ points _ "CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        cout << "**********************************************************************" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
