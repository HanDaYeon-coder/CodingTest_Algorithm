#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
vector<int> v[10004];
int visited[10004];
int value = 0;
vector<pair<int,int>> answers;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void dfs(int x) {
    visited[x] = 1;

    for(int i=0; i<v[x].size(); i++) {
        if(visited[v[x][i]] == 0){
            dfs(v[x][i]);
            value++;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<M; i++) {
        cin>>A >> B;
        v[B].push_back(A);
    }

    for(int i=1; i<=N; i++) {
        dfs(i);
        answers.push_back({value, i});
        value = 0;
        memset(visited, 0, sizeof(visited));
    }
    
    sort(answers.begin(), answers.end(), cmp);

    int maxValue = answers[0].first;

    for(int i=0; i<answers.size(); i++) {
        if(maxValue == answers[i].first) {
            cout<<answers[i].second<<" ";
        } else {
            break;
        }
    }
}
