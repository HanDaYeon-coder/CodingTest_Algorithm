#include <bits/stdc++.h>
using namespace std;

int N;
string name;
string result;
int a[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>name;
        a[name[0]-'a']++;
    }
    
    
    for(int i=0; i<26; i++){
        if(a[i]>=5){
            result.push_back(i + 'a');
        }
    }

    if(result.length() == 0){
        cout<< "PREDAJA"<<"\n";
    } else {
        cout<<result<<"\n";
    }

    return 0;
}
