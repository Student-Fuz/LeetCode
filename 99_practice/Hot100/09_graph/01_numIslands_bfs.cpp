#include <bits/stdc++.h>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

vector<vector<int>> dir = 
{
    {0, 1},
    {0, -1}, 
    {1, 0},
    {-1, 0}
};

// bfs
void bfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
    
            if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
    
            if(!visited[nextx][nexty] && grid[nextx][nexty] == '1'){
                visited[nextx][nexty] = true;
                q.push({nextx, nexty});
            }
        }
    }
}

// Solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size())
            return -1;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    result++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return result;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}