#include <bits/stdc++.h>
using namespace std;

int n = 9;
int r = 7;
int v[9];
int x;

void combi(int start, vector<int> b){
    if(b.size() == r) {
        int sum = 0;
        for(int i=0; i<r; i++){
            sum += v[b[i]];
        }
        if(sum == 100){
            for(int i=0; i<r; i++){
                cout<<v[b[i]]<<"\n";
            }
            exit(0);
        }
        return;
    }
    for(int i=start+1; i<n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<9; i++){
        cin>>v[i];
    }
    
    sort(v, v+9);

    vector<int> b;
    combi(-1, b);

    return 0;
}
