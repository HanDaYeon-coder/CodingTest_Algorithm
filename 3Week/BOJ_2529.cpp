#include <bits/stdc++.h>
using namespace std;

int N;
char arr[10];
vector<int> b;
vector<string> results;

void combi(int a) {
    if(b.size() == N+1) {
        do {
            bool is_result = true;
            string result;

            for(int i=0; i<N; i++){
                if(arr[i] == '>'){
                    if(b[i] < b[i+1]){
                        is_result = false;
                        break;
                    }
                } else {
                    if(b[i] > b[i+1]){
                        is_result = false;
                        break;
                    }
                }
                result += (b[i]+'0');
            }

            if(is_result){
                result += (b[N]+'0');
                results.push_back({result});
            }
        } while(next_permutation(b.begin(), b.end()));
        
        return;
    }

    for(int i=a+1; i<=9; i++){
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
        cin>>arr[i];
    }

    combi(-1);

    sort(results.begin(), results.end());

    cout<<results[results.size()-1]<<"\n";
    cout<<results[0]<<"\n";
}
