#include <bits/stdc++.h>
using namespace std;

int N, team;
string scoreTime;
int teamA, teamB;
vector<pair<int, int>> v;
int aTime, bTime;

void printTime(int times) {
    if(times == 0) {
        cout<<"00";
    } else if(times < 10) {
        cout<<"0"<<times;
    } else {
        cout<<times;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> team >> scoreTime;

        int nowMinutes = ((scoreTime[0] - '0') * 10 + (scoreTime[1] - '0')) * 60;
        int nowSeconds = (scoreTime[3] - '0') * 10 + (scoreTime[4] - '0');
        v.push_back({nowMinutes+nowSeconds, team});
    }

    for(int i=0; i<N; i++){
        if(v[i].second == 1) {
            teamA++;
        } else {
            teamB++;
        }

        if(i != N-1){
            if(teamA > teamB) {
                aTime += (v[i+1].first - v[i].first);
            } else if (teamA < teamB) {
                bTime += (v[i+1].first - v[i].first);
            }
        } else {
            if(teamA > teamB) {
                aTime += (48*60 - v[i].first);
            } else if (teamA < teamB) {
                bTime += (48*60 - v[i].first);
            }
        }
    }

    printTime(aTime/60); cout << ":"; printTime(aTime%60); cout << "\n";
    printTime(bTime/60); cout << ":"; printTime(bTime%60); cout << "\n";
}
