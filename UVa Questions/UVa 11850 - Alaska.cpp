/*
The only detail is that she has to come back, so there are two conditions 
to be possible.
*/
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    int location, i;

    while(scanf("%d", &n) && n){
        vector<int> locations;
        locations.clear();
        int flag = 0;
        while(n--){
            scanf("%d", &location);
            locations.push_back(location);
        }
        sort(locations.begin(),locations.end());
        for(i=0;i<locations.size()-1;i++){
            if(locations[i+1] - locations[i]>200) flag++;
        }
        if(flag == 0 && (locations[locations.size() - 1] + 100 >= 1422)) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}

