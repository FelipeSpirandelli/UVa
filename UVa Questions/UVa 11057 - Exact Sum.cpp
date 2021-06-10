#include <bits/stdc++.h>
#define _  << " " <<
#define pb push_back
#define line << endl
#define rep(i,a,b) for(int i = a; i < b; i++)
#define EPS 1e-9
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF=0xfffffff;
const int mod=1e9+7;


int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, price, aux, point, other_value, low, high, mid, MIN;
    vi books;
    ii best_pair;

    while(cin >> N)
    {
        books.clear();
        rep(i,0,N)
        {
            cin >> aux;
            books.pb(aux);
        }
        cin >> price;
        MIN = INF;
        sort(books.begin(), books.end());
        rep(i,0,N)
        {
            point = books[i];
            other_value = price - point;
            low = i+1;
            high = N;
            mid = (low+high)/2;
            while(books[mid] != other_value)
            {
                if(books[mid] > other_value)
                {
                    high = mid;
                }
                else
                {
                    low = mid;
                }
                mid = (low+high)/2;
                if(mid == low || mid == high)
                    break;
            }
            if(books[mid] == other_value)
            {
                if(MIN > abs(point - other_value))
                {
                    MIN = abs(point - other_value);
                    best_pair = make_pair(point, other_value);
                }
            }
        }
        cout << "Peter should buy books whose prices are" _ best_pair.first _ "and" _ best_pair.second << "." line line;
    }


    return 0;
}




