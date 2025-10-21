#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int start = 0;
    for (int i = 0; i < n; i++) {
        int state;
        cin >> state;
        if (state == 1) start |= (1 << i);
    }

    vector<int> rs(n, 0);
    for (int i = 0; i < m; i++) {
        int sw, lamp;
        cin >> sw >> lamp;
        sw--, lamp--;
        rs[sw] |= (1 << lamp);
    }
    for(int i = 0; i < n; i++){
        rs[i] |= (1 << i);
        //cout << rs[i] << endl;;
    }
    

    queue<pair<int, vector<int>>> q;
    vector<int> minDist(1 << n, -1);
    q.push({start, {}});
    minDist[start] = 0;

    while (!q.empty()) {
        auto [state, steps] = q.front();
        q.pop();
        //cout << state << endl;

        if (state == 0) {   
            for(int i = 0; i < steps.size(); i++){
                if(i == 0) cout << steps[i];
                else cout << " " << steps[i];
            }
            return 0;
        }

        for (int i = 0; i < n; i++) {
            int r = rs[i];
            int newState = state ^ r;
            //cout << newState << " " << r << endl;
            //if (newState == 0) {         
            //        cout << steps+1 << endl;
            //        return 0;
            //}
            if (minDist[newState] == -1) {
                vector<int> newStep = steps;
                steps.push_back(i+1);
                minDist[newState] = steps.size();
                q.push({newState, steps});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}

