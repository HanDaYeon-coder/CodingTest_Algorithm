#include <bits/stdc++.h>
using namespace std;

string s;
char a[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true) {
        cin>>s;

        if(s == "end") {
            break;
        }

        bool is_accept = true;
        bool is_in_a = false;
        int b_nums = 0;
        int a_nums = 0;

        for(int i=0; i<s.size(); i++) {
            bool is_a = false;

            for(int j=0; j<5; j++) {
                if(s[i] == a[j]) {
                    is_a = true;
                    is_in_a = true;
                    break;
                }
            }

            if(is_a) {
                a_nums++;
                b_nums = 0;

                if(a_nums >= 3) {
                    is_accept = false;
                    break;
                }
            } else {
                b_nums++;
                a_nums = 0;
                
                if(b_nums >= 3) {
                    is_accept = false;
                    break;
                }
            }

            if(i!=s.size()-1 and s[i+1] != 'e' and s[i+1] != 'o' and s[i+1] == s[i]) {
                is_accept = false;
                break;
            }
        }

        if(is_in_a and is_accept) {
            cout<< "<" << s << ">" << " is acceptable."<<"\n";
        } else {
            cout<< "<" << s << ">" << " is not acceptable."<<"\n";
        }
    }
}
