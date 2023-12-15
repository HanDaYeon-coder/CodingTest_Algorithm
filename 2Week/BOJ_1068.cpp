#include <bits/stdc++.h>
using namespace std;

int N, a, b;
int arr[54];
vector<int> tree[54];
int root;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }

    cin>>b;

    for(int i=0; i<N; i++){
        if(i==b) {
            if(arr[i]==-1){
                cout<<0<<"\n";
                return 0;
            }
            continue;
        }
        
        if(arr[i]==-1) {
            root = i;
        } else if(arr[i] == b) {
            continue;
        } else {
            tree[arr[i]].push_back(i);
        }
    }

    queue<int> que;
    que.push(root);

    while(!que.empty()) {
        int here = que.front();
        que.pop();

        if(tree[here].size() == 0) {
            answer++;
        }
        for(int i=0; i<tree[here].size(); i++) {
            que.push(tree[here][i]);
        }
    }

    cout<<answer<<"\n";
    return 0;
}
