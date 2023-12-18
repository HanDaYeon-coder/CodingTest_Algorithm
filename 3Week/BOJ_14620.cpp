#include <bits/stdc++.h>
using namespace std;

int N;
int arr[14][14];
int visited[14][14];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int min_cost = 200*5*3;
vector<int> b;
vector<pair<int,int>> flowers;

void combi(int a) {
    if(b.size()==3) {
        bool is_flower = true;
        int sum_cost = 0;

        for(int j=0; j<3; j++){
            int x = flowers[b[j]].first;
            int y = flowers[b[j]].second;

            visited[x][y] = 1;
            sum_cost += arr[x][y];

            for(int k=0; k<4; k++) {
                int nx = dx[k] + x;
                int ny = dy[k] + y;

                if(visited[nx][ny] != 0) {
                    is_flower = false;
                    break;
                }
                visited[nx][ny] = 1;
                sum_cost += arr[nx][ny];
            }

            if(!is_flower){
                break;
            }
        }

        if(is_flower and min_cost > sum_cost){
            min_cost = sum_cost;
        }

        memset(visited, 0, sizeof(visited));
        return;
    }

    for(int i=a; i<flowers.size(); i++){
        b.push_back(i);
        combi(i);
        b.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>arr[i][j];

            if(i!=0 and j!=0 and i!=N-1 and j!=N-1){
                flowers.push_back({i,j});
            }
        }
    }

    combi(0);

    cout<<min_cost<<"\n";
}
