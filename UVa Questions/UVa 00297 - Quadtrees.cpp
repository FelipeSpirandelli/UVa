#include <bits/stdc++.h>
#define _  << " " <<
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int im[32][32];
int black;

void build ( char q, int a, int b, int c){
    cin >> q;
    if(q == 'p'){
            build(q, a , b + c/2, c/2);
            build(q, a , b, c/2);
            build(q, a + c/2, b, c/2);
            build(q, a + c/2, b + c/2 , c/2);
    }
    else if( q == 'f'){
        for(int i = a; i < a + c; i++){
            for(int j = b; j < b + c; j++){
                if(im[i][j] == 0){
                    im[i][j] = 1;
                    black++;
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N,i,j;
    char pixel;

    cin >> N;
    cin.ignore();
    while(N--){
        for(i = 0; i < 32; i++){
            for(j=0;j<32;j++){
                im[i][j] = 0;
            }
        }
        black = 0;
        build(pixel, 0, 0, 32);
        build(pixel, 0, 0, 32);
        cout << "There are " << black _ "black pixels." << endl;
    }

    return 0;
}
