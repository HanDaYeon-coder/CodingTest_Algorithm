#include <bits/stdc++.h>
using namespace std;

string S;
int a[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>S;

    for(int i=0; i<S.size(); i++){
        a[S[i]-'a']++;
    }

    for(int i=0; i<26; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
