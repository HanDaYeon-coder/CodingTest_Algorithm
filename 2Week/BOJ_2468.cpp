#include <bits/stdc++.h>
using namespace std;

int N;
int arr[104][104];
set<int> levels;
int visited[104][104];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int max_result = 1;

void dfs(int x, int y, int level) {
    visited[x][y] = 1;

    for(int i=0; i<4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx>=N or ny>=N or nx <0 or ny <0 or visited[nx][ny] == 1) {
            continue;
        }
        if(arr[nx][ny] > level) {
            dfs(nx, ny, level);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>arr[i][j];
            levels.insert(arr[i][j]);
        }
    }

    for(auto level : levels) {
        memset(visited, 0, sizeof(visited));
        int result = 0;

        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                if(arr[j][k] > level and visited[j][k] == 0) {
                    dfs(j, k, level);
                    result++;
                }
            }
        }

        if(result > max_result) {
            max_result = result;
        }
    }

    cout<<max_result<<"\n";
}
