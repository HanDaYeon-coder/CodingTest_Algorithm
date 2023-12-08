#include <bits/stdc++.h>
using namespace std;

string a,result;
int arr[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>a;

    int len = a.length();

    for(int i=0; i<len; i++){
        arr[a[i]-'A'] += 1;
    }

    if(len%2 == 0) { //짝수인 경우
        for(int i=0; i<26; i++) {
            if(arr[i]%2 == 1) {
                cout<<"I'm Sorry Hansoo"<<"\n";
                return 0;
            } 
            string k;
            for(int j=0; j<arr[i]/2; j++){
                k += ('A'+i);
            }
            result += k;
        }
        
        string original_result = result;
        reverse(result.begin(), result.end());
        cout<<original_result + result<<"\n";
    } else { //홀수인 경우 -> 홀수 개의 알파벳이 1개만 존재해야함.
        int center_cnt = 0;
        int center_num = 0;

        for(int i=0; i<26; i++) {
            if(center_cnt >= 2) {
                cout<<"I'm Sorry Hansoo"<<"\n";
                return 0;
            }
            if(arr[i]%2 == 1) {
                center_cnt += 1;
                center_num = i;
            } 
            
            string k;
            for(int j=0; j<arr[i]/2; j++){
                k += ('A'+i);
            }
            result += k;
        }

        string original_result = result;
        reverse(result.begin(), result.end());
        cout<<original_result + char(center_num+'A') + result<<"\n";
    }
}
