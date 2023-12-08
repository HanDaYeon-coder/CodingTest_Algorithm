#include <bits/stdc++.h>
using namespace std;

int n;
string pattern, a, s;

int main() {
    cin >> n;
    cin >> pattern;
    
    int pos = pattern.find('*');
    string pre = pattern.substr(0, pos);
    string suf = pattern.substr(pos+1);
    
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s.size() < pre.size() + suf.size()) {
            cout<<"NE"<<"\n";
        } else if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) {
            cout<<"DA"<<"\n";
        } else {
            cout<<"NE"<<"\n";
        }
    }

    return 0;
}
