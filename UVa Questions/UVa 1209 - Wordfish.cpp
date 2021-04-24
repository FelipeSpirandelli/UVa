#include <bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<n;i++)
using namespace std;


int main(){

    int i,j,k, auxMax_within_word, aux_Max_all_words;
    string username;
    string aux;
    vector<string> passwords;

    while(cin >> username){
        passwords.clear();
        aux = username;
        rep(i,0,10){prev_permutation(aux.begin(), aux.end());}
        rep(i,0,10){
            passwords.push_back(aux);
            next_permutation(aux.begin(), aux.end());
        }
        passwords.push_back(username);
        rep(i,0,10){
            next_permutation(username.begin(), username.end());
            passwords.push_back(username);
        }
        aux_Max_all_words = 0;
        rep(i,0,21){
            auxMax_within_word = 100;
            rep(j,0,username.size()-1){
                if(abs(passwords[i][j] - passwords[i][j+1]) < auxMax_within_word ){
                    auxMax_within_word = abs(passwords[i][j] - passwords[i][j+1]);
                }
            }
            if(aux_Max_all_words < auxMax_within_word){
                aux_Max_all_words = auxMax_within_word;
                aux = passwords[i];
            }
            else if(aux_Max_all_words == auxMax_within_word && passwords[i] < aux){
                aux = passwords[i];
            }
        }
        cout << aux << aux_Max_all_words << endl;
    }
    return 0;
}

