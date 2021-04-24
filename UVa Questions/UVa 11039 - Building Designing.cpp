#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

bool comp(int A, int B){
    return abs(A) < abs(B);

}

int main(){
    ios_base::sync_with_stdio(false);

    int p, f, auxFloor, height;
    int i;
    bool isNegative;
    vector<int> floors;

    cin >> p;
    cin.ignore();
    while(p--){
        floors.clear();
        cin >> f;
        cin.ignore();
        rep(i,0,f){
            cin >> auxFloor;
            cin.ignore();
            floors.push_back(auxFloor);
        }
        sort(floors.begin(), floors.end(),comp);
        if(floors[0] < 0) isNegative = true;
        else if (floors[0] > 0)isNegative = false;
        height = 1;
        if(f == 0) height = 0;
        rep(i,1,f){
            if(isNegative == true){
                if(floors[i] > 0){
                    height++;
                    isNegative = false;
                }
            }
            else{
                if(floors[i] < 0){
                    height++;
                    isNegative = true;
                }
            }
        }

        cout << height << endl;
    }

    return 0;
}

