#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1183

bool isNeighbor(string a, string b){
    int diff = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            diff++;
            if(diff >= 2){
                return false;
            }
        }
    }
    if(diff) return true;
    else return false;
}

int main() {

    int n;

    string s, t;

    cin >> n >> s >> t;

    vector<string> strs;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        strs.push_back(str);
    }

    int strNum = 1;
    queue<string> q;
    q.push(s);
    vector<bool> visited(n, false);

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            string str = q.front();
            q.pop(); 
            if(isNeighbor(str, t)){
                cout << strNum+1 << endl;
                return 0;
            }
            for(int j = 0; j < strs.size(); j++){
                string nextStr = strs[j];
                if(isNeighbor(str, nextStr) && visited[j] == false){
                    visited[j] = true;
                    q.push(nextStr);
                }
            }
        }

        strNum++;
    }

    cout << 0 << endl;

    return 0;
}