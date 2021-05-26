#include <bits/stdc++.h>
using namespace std;

map<string,int> all_words;

void initial(){
    char a,b,c,d,e, aux[6];
    int counting = 0;

    for( a ='a'; a<= 'z' ; a++){
        aux[0] = a;
        aux[1] = '\0';
        all_words[aux] = ++counting;
    }
    for( a ='a'; a<= 'y' ; a++){
        for(b = a + 1; b <= 'z'; b++){
            aux[0] = a;
            aux[1] = b;
            aux[2] = '\0';
            all_words[aux] = ++counting;
        }
    }
    for( a ='a'; a <= 'x' ; a++){
        for(b= a + 1; b <= 'y'; b++){
            for(c = b + 1; c <= 'z'; c++){
                aux[0] = a;
                aux[1] = b;
                aux[2] = c;
                aux[3] = '\0';
                all_words[aux] = ++counting;
            }
        }
     }
     for( a ='a'; a<= 'w' ; a++){
        for(b = a+1; b <= 'x'; b++){
            for( c = b+1; c<= 'y' ; c++){
                for(d= c+1; d <= 'z'; d++){
                    aux[0] = a;
                    aux[1] = b;
                    aux[2] = c;
                    aux[3] = d;
                    aux[4] = '\0';
                    all_words[aux] = ++counting;
                }
            }
        }
     }
     for( a ='a'; a<= 'v' ; a++){
        for(b=a+1; b <= 'w'; b++){
            for( c =b+1; c<= 'x' ; c++){
                for(d = c+1; d <= 'y'; d++){
                    for(e = d+1; e <= 'z'; e++){
                        aux[0] = a;
                        aux[1] = b;
                        aux[2] = c;
                        aux[3] = d;
                        aux[4] = e;
                        aux[5] = '\0';
                        all_words[aux] = ++counting;
                    }
                }
            }
        }
     }
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    map<string,int>::iterator it;

    initial();
    while(cin >> s){
        cin.ignore();
        if(all_words.find(s) != all_words.end()){
            it = all_words.find(s);
            cout << it->second << endl;
        }
        else{
            cout << 0 << endl;
        }
    }

    return 0;
}
