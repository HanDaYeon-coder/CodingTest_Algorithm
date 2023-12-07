#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    getline(cin, S);

    for(int i=0; i<S.length(); i++) {
        if(S[i] >= 'A' and S[i] <= 'Z'){
            if (S[i] + 13 > 'Z') {
                cout<< char (S[i] + 13 - 26);
            } else {
                cout<< char (S[i]+13);
            }
        } else if(S[i] >= 'a' and S[i] <= 'z') {
            if (S[i] + 13 > 'z') {
                cout<< char (S[i] + 13 - 26);
            } else {
                cout<< char (S[i]+13);
            }
        } else {
            cout<<S[i];
        }
    }

    return 0;
}
