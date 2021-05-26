//Competitive Programming 3
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
    int N ;
    int tmp = -100, used, abcde, fghij, success;

    while(cin >> N && N){
        success = 0;
        if(tmp != -100)
            cout << endl;
        for(fghij = 1234; fghij <= 98765/N ; fghij++){
            abcde = N * fghij;
            used = (fghij < 10000) ;
            tmp = abcde;
            while(tmp){
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while(tmp){
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if(used == (1 << 10) - 1){
                if(fghij < 10000)
                    cout << abcde << " / 0" << fghij << " = " << N <<endl;
                else
                    cout << abcde << " / " << fghij << " = " << N <<endl;
                success++;
            }
        }
        if(success == 0)
            cout << "There are no solutions for " << N << "." << endl;

    }


    return 0;
}
