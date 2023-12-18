#include <bits/stdc++.h>
using namespace std;

int R, C;
string arr[24];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visited[24][24];
int visited_char[30];
int answer;

void dfs(int x, int y, int depth) {
    if(depth > answer) {
        answer = depth;
    }

    for(int i=0; i<4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if(nx < 0 or ny < 0 or nx >= R or ny >= C) {
            continue;
        }

        if(visited_char[arr[nx][ny]-'A'] == 0 and visited[nx][ny] == 0) {
            visited_char[arr[nx][ny]-'A'] = 1;
            visited[nx][ny] = 1;
            dfs(nx, ny, depth+1);
            visited[nx][ny] = 0;
            visited_char[arr[nx][ny]-'A'] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;

    for(int i=0; i<R; i++){
        cin>>arr[i];
    }

    visited[0][0] = 1;
    visited_char[arr[0][0]-'A'] = 1;
    dfs(0,0,1);

    cout<<answer<<"\n";
}
