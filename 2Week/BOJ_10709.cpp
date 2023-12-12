#include <bits/stdc++.h>
using namespace std;

int H, W;
char X;
int result[104][104];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> H >> W;

    for(int i=0; i<H; i++) {
        int cloud = -1;

        for(int j=0; j<W; j++) {
            cin>>X;

            if(X == 'c') {
                result[i][j] = 0;
                cloud = j;
            } else {
                if(cloud == -1) {
                    result[i][j] = -1;
                } else {
                    result[i][j] = j-cloud;
                }
            }
        }
    }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}
