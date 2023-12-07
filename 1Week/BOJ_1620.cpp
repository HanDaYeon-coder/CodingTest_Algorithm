#include <bits/stdc++.h>
using namespace std;

map<string, int> a;
map<int, string> b;
string c;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin>>c;
        a.insert({c, i});
        b.insert({i, c});
    }

    string q;
    for(int i=0; i<M; i++) {
        cin>>q;
        if(atoi(q.c_str()) == 0) { // 문자열인경우
            cout<<a[q]<<"\n";
        } else {
            cout<<b[atoi(q.c_str())]<<"\n";
        }
    }
}
