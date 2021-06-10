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
    int a,b,c,d;
    float fa,fb,fc,fd;
    long long int d1,d2;
    for(a = 1; 4*a <= 2000; a++){
        for(b = a; a+3*b <=2000; b++){
            for(c = b; a+b+2*c <=2000; c++){
                d1 = (a+b+c);
                d2 = (long long )a*b*c;
                if(d2 - 1000000 <= 0)
                    continue;
                if((d1*1000000) % (d2-1000000) == 0){
                    d = (d1*1000000)/(d2-1000000);
                    if(d1 + d <= 2000 && d >= c){
                        fa = a/100.0; fb = b/100.0; fc = c/100.0; fd = d/100.0;
                        cout << fixed << setprecision(2) << fa _ fb _ fc _ fd << endl;
                    }
                }
            }
        }
    }
    return 0;
}
