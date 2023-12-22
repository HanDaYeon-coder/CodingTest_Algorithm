#include <bits/stdc++.h>
using namespace std;

int K;
long long arr[1030];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K;

    long long k = pow(2, K)-1;

    for(int i=1; i<=k; i++) {
        cin>>arr[i];
    }

    for(int i=0; i<K; i++){
        int moves = pow(2, K-i-1);

        for(int j=moves; j<=k; j+=moves){
            if(arr[j]!=-1){
                cout<<arr[j]<<" ";
                arr[j] = -1;
            }
        }
        cout<<"\n";
    }
}
