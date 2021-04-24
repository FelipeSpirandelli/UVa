#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;

struct participant{
    int ID;
    int time;
    int problemsSolved;
    int rejects[9];
    bool problems[9];
    bool isParticipating;
};

void zero(struct participant *A, int i){
    A->ID = i + 1;
    A->problemsSolved = 0;
    A->time = 0;
    rep(i,0,9){
        A->problems[i] = false;
    }
    rep(i,0,9){
        A->rejects[i] = 0;
    }
    A->isParticipating = false;
}

bool comp(struct participant A, struct participant B){
    if (A.problemsSolved != B.problemsSolved) return A.problemsSolved > B.problemsSolved;
    else if(A.time != B.time) return A.time < B.time;
    else return A.ID < B.ID;
}


int main(){
    ios_base::sync_with_stdio(false);

    int t;
    int i, problemNo, caso = 0;
    char auxChar;
    string s;
    struct participant contestant[100];
    struct participant auxContestant;

    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        rep(i,0,100){
            zero(&contestant[i], i);
        }
        while(getline(cin, s) && s.size() > 0){
            stringstream ss(s);
            ss >> auxContestant.ID >> problemNo >> auxContestant.time >> auxChar;
            if(auxChar == 'C' && contestant[auxContestant.ID - 1].problems[problemNo-1] == false){
                contestant[auxContestant.ID - 1].time +=  contestant[auxContestant.ID - 1].rejects[problemNo-1] * 20 + auxContestant.time;
                contestant[auxContestant.ID - 1].rejects[problemNo-1] = 0;
                contestant[auxContestant.ID - 1].problemsSolved++;
                contestant[auxContestant.ID - 1].isParticipating = true;
                contestant[auxContestant.ID - 1].problems[problemNo-1] = true;
            }
            else if(auxChar == 'I'){
                contestant[auxContestant.ID - 1].rejects[problemNo - 1]++;
                contestant[auxContestant.ID - 1].isParticipating = true;
            }
            else contestant[auxContestant.ID - 1].isParticipating = true;
        }
        sort(contestant, contestant + 100, comp);
        rep(i,0,100){
            if(contestant[i].isParticipating == true){
                cout << contestant[i].ID << " " << contestant[i].problemsSolved << " " << contestant[i].time << endl;
            }
        }
        if(t != 0) cout << endl;
    }

    return 0;
}

