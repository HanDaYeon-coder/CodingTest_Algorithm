#include <bits/stdc++.h>
using namespace std;

string a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a;

    string original_a = a;

    reverse(a.begin(), a.end());

    if(original_a == a){
        cout<<1<<"\n";
    } else {
        cout<<0<<"\n";
    }

    return 0;
}
