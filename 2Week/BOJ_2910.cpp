#include <bits/stdc++.h>
using namespace std;

int N, C, X;
map<int, pair<int,int>> m; // key = 숫자, value = {나온 개수, 처음 나온 수의 인덱스}
set<int> s;
set<pair<int, pair<int,int>>, greater<pair<int, pair<int,int>>>> result; // {나온개수, N-처음 나온 수의 인덱스, 숫자}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> C;

    for(int i=0; i<N; i++) {
        cin>>X;
        if(m[X].first == 0) {
            m[X].second = N-i;
            s.insert(X);
        }
        m[X].first += 1;
    }

    for(auto i : s) {
        result.insert({m[i].first, {m[i].second, i}});
    }

    for(auto i : result) {
        for(int j=0; j<i.first; j++) {
            cout<<i.second.second<<" ";
        }
    }
}
