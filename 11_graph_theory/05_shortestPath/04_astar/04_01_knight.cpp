#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1203

vector<vector<int>> dir = {
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1}
};

struct node{
    int x;
    int y;
    int step;
    int dist;
};

class MyCmp{
public:
    bool operator()(const node& l, const node & r){
        return l.dist + l.step*5 > r.dist + r.step*5;
    }
};

int distance(const pair<int, int>& start, const pair<int, int>& end){
    return (start.first - end.first)*(start.first - end.first) +(start.second - end.second)*(start.second - end.second);
}

int astar(const pair<int, int>& start, const pair<int, int>& end){
    int step = 0;
    set<pair<int, int>> visited;

    priority_queue<node, vector<node>, MyCmp> q;
    q.push({start.first, start.second, 0, distance(start, end)});
    visited.insert(start);

    while(!q.empty()){
        node nod = q.top();
        q.pop();
        if(distance({nod.x, nod.y}, end) == 0){
            return nod.step;
        }

        for(int i = 0; i < dir.size(); i++){
            node nextNode;
            nextNode.x = nod.x + dir[i][0];
            nextNode.y = nod.y + dir[i][1];
            if(nextNode.x < 1 || nextNode.x > 1000 || nextNode.y < 1 || nextNode.y > 1000)
                continue;
            if (visited.count({nextNode.x, nextNode.y})) continue;
            visited.insert({nextNode.x, nextNode.y});

            nextNode.step = nod.step+1;
            nextNode.dist = distance({nextNode.x, nextNode.y}, end);

            q.push(nextNode);
        }
    }

    return -1;
}

int main() {

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        cout << astar({a1, a2}, {b1, b2}) << endl;
    }

    return 0;
}