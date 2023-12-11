#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int arr[104][104];
int visited[104][104];
vector<int> areas;
int result;
int area = 1;

void dfs(int x, int y) {
    visited[x][y] = 1;

    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx < 0 or ny < 0 or nx >= N or ny >= M or visited[nx][ny] == 1) {
            continue;
        }
        if(arr[nx][ny] == 0) {
            dfs(nx, ny);
            area++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x1, y1, x2, y2;

    cin >> M >> N >> K;

    for(int i=0; i<K; i++){
        cin>>x1>>y1;
        cin>>x2>>y2;

        for(int j=x1; j<x2; j++) {
            for(int k=y1; k<y2; k++) {
                arr[j][k] = 1;
            }
        }
    }

    
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(arr[j][i] == 0 and visited[j][i] == 0){
                dfs(j,i);
                areas.push_back(area);
                area = 1;
                result++;
            }
        }
    }

    cout<<result<<"\n";
    sort(areas.begin(), areas.end());

    for(auto i : areas) {
        cout<<i<<" ";
    }
}
