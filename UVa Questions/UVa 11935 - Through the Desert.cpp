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

vector<pair<int,string> > events;
vi consume_per_100;

bool can(double gas){
    double total = 0.0;
    int distance_now = 0;
    int leaks = 0, position = 0;
    int consume = consume_per_100[0];
    rep(i,0, events.size()){
        if(events[i].first > distance_now){
            total+= (events[i].first - distance_now) * consume/100.0;
            distance_now = events[i].first;
        }
        if(total > gas)
            return false;
        if(events[i].second == "Leak"){
            consume += 100;
            leaks++;
        }
        else if(events[i].second == "Gas"){
            total = 0;
        }
        else if(events[i].second == "Mechanic"){
            consume -= leaks * 100;
            leaks = 0;
        }
        else if(events[i].second == "Fuel"){
            consume += -consume_per_100[position] + consume_per_100[position+1];
            position++;
        }
        else if(events[i].second == "Goal"){
            if(total > gas)
                return false;
            else
                return true;
        }

    }

}

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s, trash;
    int distance, n;

    while(cin >> distance >> s >> trash >> n && n){
        consume_per_100.clear();
        consume_per_100.pb(n);
        cin.ignore();
        events.clear();
        while(getline(cin, trash)){
            stringstream ss(trash);
            ss >> distance >> s;
            events.pb(make_pair(distance, s));
            if(s == "Fuel"){
                ss >> trash >> n;
                consume_per_100.pb(n);
            }
            if(s == "Goal") break;
        }
        double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
        rep(i,0,50){
            mid = (lo + hi)/2;
            if(can(mid)) {
                ans = mid;
                hi = mid;
            }
            else
                lo = mid;
        }
            cout << fixed << setprecision(3)<< ans line;
    }

    return 0;
}

