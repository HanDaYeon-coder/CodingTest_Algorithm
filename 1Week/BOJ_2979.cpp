#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int x[3];
int y[3];
long long result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>A>>B>>C;

    for(int i=0; i<3; i++){
        cin>>x[i]>>y[i];
    }

    for(int i=1; i<=100; i++){
        int cnt = 0;
        for(int j=0; j<3; j++){
            if(i > x[j] and i <= y[j]){
                cnt++;
            }
        }

        if(cnt == 1) {
            result += A;
        } else if(cnt == 2){
            result += 2*B;
        } else if(cnt==3) {
            result += 3*C;
        }
    }

    cout<<result<<"\n";

    return 0;
}
