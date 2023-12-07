#include <bits/stdc++.h>
using namespace std;

int a[100004];
int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>> N >> K;
    
    for(int i=0; i < N; i++) {
        cin>>a[i];
    }

    int sum = 0;
    for(int i=0; i<K; i++) {
        sum += a[i];
    }

    int result = sum;

    for(int i=K; i<N; i++) {
        sum += a[i];
        sum -= a[i-K];
        if(result < sum ) {
            result = sum;
        }
    }

    cout<<result<<"\n";

    return 0;
}
