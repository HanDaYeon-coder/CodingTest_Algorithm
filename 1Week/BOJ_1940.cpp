#include <bits/stdc++.h>
using namespace std;

int N, M, x;
int a[100004];
int result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin>>x;
        a[x] = 1;
    }

    for(int j=0; j<=100000; j++) {
        if(a[j]==1) {
            if(j >= M-j) {
               break; 
            }
            if( (M-j) <= 100000 and a[M-j] == 1){
                result++;
            }
        }
    }

    cout<<result<<"\n";
}
