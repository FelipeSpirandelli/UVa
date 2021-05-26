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
    int f, r, aux;
    double maxspread, spread;
    vi fteeth, rteeth;
    vector<float> drive_ratios;

    while( cin >> f && f){
        cin >> r;
        fteeth.clear();
        rteeth.clear();
        drive_ratios.clear();
        rep(i,0,f){
            cin >> aux;
            fteeth.push_back(aux);
        }
        rep(i,0,r){
            cin >> aux;
            rteeth.push_back(aux);
        }
        rep(i,0,fteeth.size()){
            rep(j,0,rteeth.size()){
                drive_ratios.push_back((rteeth[j]*1.0)/fteeth[i]);
            }
        }
        maxspread = 0;
        sort(drive_ratios.begin(), drive_ratios.end());
        rep(i,0,drive_ratios.size() - 1){
            spread = drive_ratios[i+1]/drive_ratios[i];
            if( spread > maxspread)
                maxspread = spread;
        }
        cout << fixed << setprecision(2) << maxspread << endl;

    }


    return 0;
}
