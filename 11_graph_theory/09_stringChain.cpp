#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1183

// BFS

int main() {
    int n;
    cin >> n;
    string beginStr, endStr;
    cin >> beginStr >> endStr;

    unordered_set<string> strSet;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        strSet.insert(str);
    }

    unordered_map<string, int> visitedMap;
    visitedMap.insert({beginStr, 1});

    queue<string> q;
    q.push(beginStr);
    while(!q.empty()){
        string curPos = q.front();
        q.pop();

        for(int i = 0; i < curPos.size(); i++){
            string newPos = curPos;
            for(int j = 0; j < 26; j++){
                newPos[i] = 'a' + j;

                // 如果抵达终点
                if(newPos == endStr){
                    cout << visitedMap[curPos]+1 << endl;
                    return 0;
                }

                // 如果到了合法的新的地方
                if(strSet.find(newPos) != strSet.end()
                    && visitedMap.find(newPos) == visitedMap.end()){
                    
                    visitedMap[newPos] = visitedMap[curPos]+1;
                    q.push(newPos);
                }
            }

        }
    }

    cout << -1 << endl;

    return 0;
}