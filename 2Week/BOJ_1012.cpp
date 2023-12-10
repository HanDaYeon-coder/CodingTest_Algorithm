#include <bits/stdc++.h>
using namespace std;

int T, M, N, K, X, Y;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[54][54];
int visited[54][54];

void dfs(int x, int y) {
    visited[x][y] = 1;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= M or ny >= N or nx <0 or ny <0) {
            continue;
        }
        if(arr[nx][ny] == 1 and visited[nx][ny]==0) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>T;

    for(int i=0; i<T; i++) {
        cin>>M>>N>>K;

        int result = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for(int j=0; j<K; j++) {
            cin>>X>>Y;
            arr[X][Y] = 1;
        }

        for(int k=0; k<M; k++) {
            for(int l=0; l<N; l++) {
                if(arr[k][l] == 1 and visited[k][l] == 0) {
                    result++;
                    dfs(k, l);
                }
            }
        }

        cout<<result<<"\n";
    }

}
