#include <bits/stdc++.h>
#define _  << " " <<
#define pb push_back
#define line << endl
#define doisp << ":"
#define rep(i,a,b) for(int i = a; i < b; i++)
#define EPS 1e-15
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
const int INF=0xfffffff;
const int mod=1e9 + 7;

int da[] = {0, 0, 1, 1, 1, -1, -1, -1};
int db[] = {1, -1, 0, 1, -1, 0, 1, -1};
char ma[100][100], aux[100][100];
int n, m;

int floodfill(int a, int b){
    if(a < 0 || a >= n || b < 0 || b >= m)
        return 0;
    if(aux[a][b] != 'W')
        return 0;
    aux[a][b] = 'C';
    int ans = 1;
    rep(i,0,8){
        ans += floodfill(a+da[i], b+db[i]);
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, first, second;
    string s;
    char sta;

    cin >> t;

    cin.ignore();
    cin.ignore();
    while(t--){
        getline(cin, s);
        m = s.size();
        n = 0;
        for(int i = 0; s.size() != 0 ; getline(cin,s), i++){
            if(!isalpha(s[0]))
                break;
            stringstream ss(s);
            n++;
            ss >> sta;
            for(int j = 0; ss ; ss >> sta, j++)
                ma[i][j] = sta;
        }
        do{
            if(s.size() == 0)
                break;
            stringstream ss(s);
            ss >> first >> second;
            rep(i,0,n)
                rep(j,0,m)
                    aux[i][j] = ma[i][j];
            cout << floodfill(--first, --second) line;
        }while(getline(cin, s));
        if(t)
            cout line;

    }

    return 0;
}
