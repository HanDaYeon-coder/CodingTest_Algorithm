#include <bits/stdc++.h>
using namespace std;

int N;
int result;
string x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    for(int i=0; i<N; i++) {
        cin>>x;

        stack<char> s;

        for(int j=0; j<x.length(); j++) {
            if(!s.empty()){
                if(s.top() == x[j]) {
                    s.pop();
                } else {
                    s.push(x[j]);
                }
            } else {
                s.push(x[j]);
            }
        }

        if(s.empty()) {
            result++;
        }
    }

    cout<<result<<"\n";
}
