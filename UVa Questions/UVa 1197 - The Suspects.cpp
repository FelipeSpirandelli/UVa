#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi students;

int fin (int a){
    if(students[a] < 0)
        return a;
    else{
        return fin(students[a]);
    }
}

void uni(int a, int b){
    if(fin(a) != fin(b)){
        if(students[fin(a)] <= students[fin(b)])
            students[fin(b)] = fin(a);
        else
            students[fin(a)] = fin(b);
    }
}

bool belong(int a, int b){
    return fin(a) == fin(b);
}

int main()
{
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n ,m, i, suspect, suspects, first, second;
    int group_size;


    while(cin >> n >> m && n != 0){
        students.clear();
        students.resize(n,-1);
        while(m--){
            cin >> group_size;
            if(group_size>0){
                cin >> first;
                group_size--;
            }
            while(group_size--){
                cin >> second;
                uni(first, second);
            }
        }
        suspect = fin(0);
        suspects = 1;
        for(i = 1; i < n; i++){
            if(fin(i) == suspect)
                suspects++;
        }
        cout << suspects << endl;
    }

    return 0;
}
