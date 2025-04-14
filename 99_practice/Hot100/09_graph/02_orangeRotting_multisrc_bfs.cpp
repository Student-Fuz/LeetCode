#include <bits/stdc++.h>
using namespace std;


// 思路1：
// 1. 首先数有多少个岛
// 2. 
// 2.1 岛上没有腐烂的橘子则返回-1
// 2.2 岛上有腐烂的橘子(不太好)

// 思路2:
// 

// 自己写TODO
vector<vector<int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

class Solution {
private:
    int bfs(const vector<vector<int>>& grid, int x, int y){
        if(!grid.size()) return 0;

        // 存放腐烂的橘子
        queue<pair<int, int>> q;

        // 队列迭代难以记录腐败轮次
        // 因此使用额外空间来存储腐败轮次
        // dis 代表 x,y 腐烂时间
        vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), -1));

        int cnt = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    dis[i][j] = 0;
                }
                else if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        int ans = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int nextx = x + dir[i][0];
                int nexty = y + dir[i][1];

                if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size() || dis[nextx][nexty]!=-1 || !grid[nextx][nexty]) continue;
                dis[nextx][nexty] = dis[x][y] + 1;
                q.push({nextx, nexty});
                if(grid[nextx][nexty] == 1){
                    cnt--;
                    ans = dis[nextx][nexty];
                    if(!cnt){
                        break;
                    }
                }
            }
        }
        return cnt ? -1 : ans;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid, 0, 0);
    }
};

int main() {

    return 0;
}