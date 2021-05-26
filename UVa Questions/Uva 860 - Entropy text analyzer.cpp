//No pretty
#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);


    string s, aux;
    map<string,int> text;
    map<string, int>::iterator it;
    int i, counting = 0;
    float entropy, max_entropy;
    int relative_entropy;

    while(cin >> s){
        if(s.compare("****END_OF_TEXT****") == 0){
            if(counting == 0){
                cout << "0 0.0 0" << endl;
            }
            else{
                entropy = 0;
                max_entropy = log10(counting);
                for(it = text.begin(); it != text.end() ; it++){
                    entropy += it->second * (max_entropy - log10(it->second))/counting;
                }
                relative_entropy = 100 * entropy/max_entropy;
                if( 100 * entropy/max_entropy - relative_entropy >= 0.5) relative_entropy+=1;
                cout << counting << " " <<  fixed << setprecision(1) << entropy << " " << relative_entropy << endl;
                counting = 0;
                text.clear();
            }
        }
        else if(s.compare("****END_OF_INPUT****") == 0) break;
        else{
            for(i = 0; i < s.length(); i++){
                switch(s[i]){
                case ',': case '.': case ':': case ';': case '!': case '?': case '"': case '(': case ')': case ' ': case '\n':
                    if(aux.length() > 0){
                        aux += '\0';
                        counting++;
                        if(text.find(aux) != text.end()){
                            it = text.find(aux);
                            it->second++;
                        }
                        else{
                            text[aux] = 1;
                        }
                        aux.clear();
                    }
                    break;
                default:
                    if(isalpha(s[i])){
                        aux += tolower(s[i]);
                    }
                    else{
                        aux += s[i];
                    }
                }
            }
        }
        if(aux.length() > 0){
            aux += '\0';
            counting++;
            if(text.find(aux) != text.end()){
                it = text.find(aux);
                it->second++;
            }
            else{
                text[aux] = 1;
            }
            aux.clear();
        }
    }

    return 0;
}
