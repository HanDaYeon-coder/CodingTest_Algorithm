#include <bits/stdc++.h>
using namespace std;

int R, C, K;
string arr[10];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visited[10][10];
int answer;
int d1, d2;

void dfs(int x, int y, int depth){
    if(x == d1 and y == d2){
        if(depth == K){
            answer++;
        }
        return;
    }
  
    if(depth >= K) { // 백 트래킹
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if(nx < 0 or ny < 0  or nx >= R or ny >= C) {
            continue;
        }

        if(visited[nx][ny] == 0 and arr[nx][ny] !='T'){ // 원복하기
            visited[nx][ny] = 1;
            dfs(nx,ny,depth+1);
            visited[nx][ny]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>R>>C>>K;

    for(int i = 0; i < R; i++){
		cin >> arr[i];
	} 

    visited[R-1][0]=1;
    d1 = 0; d2 = C-1;
    dfs(R-1,0, 1);

    cout<<answer<<"\n";
}
