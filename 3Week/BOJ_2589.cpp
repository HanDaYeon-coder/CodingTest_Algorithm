#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[54][54];
int answer;
int visited[54][54];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int x, int y) {
    queue<pair<int,int>> que;
    que.push({x, y});
    visited[x][y] = 1;
    
    while(!que.empty()) {
        pair<int,int> here = que.front();
        que.pop();

        for(int k=0; k<4; k++) {
            int nx = dx[k] + here.first;
            int ny = dy[k] + here.second;

            if(nx<0 or ny<0 or nx >= N or ny >= M) continue;
            if(visited[nx][ny] or arr[nx][ny] != 'L') continue;

            visited[nx][ny] = visited[here.first][here.second] + 1;
            que.push({nx,ny});
            answer = max(answer, visited[nx][ny]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j] == 'L') {
                bfs(i,j);
                memset(visited, 0, sizeof(visited));
            }
        }
    }

    cout<<answer-1<<"\n";
}
