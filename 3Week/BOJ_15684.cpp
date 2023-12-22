#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int a, b;
int arr[34][34];
const int INF = 1e9;
int answer = INF;

bool check() {
    for(int i=1; i<=N; i++) {
        int nb = i;

        for(int j=1; j<=H; j++) {
            if(arr[j][nb] == 1) {
                nb++;
            } else if(arr[j][nb-1]==1){
                nb--;
            } 
        }

        if(nb != i) {
            return false;
        }
    }

    return true;
}

void dfs(int here, int cnt) {
    if(cnt > 3 or answer <= cnt){
        return;
    }

    if(check()) {
        answer = cnt;
        return;
    }
    
    for(int i=here; i<=H; i++) {
        for(int j=1; j<N; j++) {
            if(arr[i][j] == 1 or arr[i][j+1] == 1 or arr[i][j-1] == 1) continue;
            arr[i][j] = 1;
            dfs(i, cnt+1);
            arr[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> H;

    for(int i=0; i<M; i++) {
        cin>>a>>b;
        arr[a][b] = 1;
    }

    dfs(1, 0);

    if(answer == INF) {
        cout<<-1<<"\n";
    } else {
        cout<<answer<<"\n";
    } 
}
