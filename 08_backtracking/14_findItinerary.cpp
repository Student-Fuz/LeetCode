#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/reconstruct-itinerary/description/

// Solution
// 第一想法错误
// 第一次成功dfs得到正确结果后不会中止搜寻
class Solution {
private:
    void backtracking(int ticketsNum, int usedSum, string curPos, unordered_map<string, map<string, int>>& ticketsMap, vector<string>& path, vector<string>& result){
        if(usedSum == ticketsNum){
            result = path;
            return;
        }
            
        
        for(auto it = ticketsMap[curPos].begin(); it != ticketsMap[curPos].end(); it++){
            if(it->second != 0){
                path.push_back(it->first);
                it->second--;
                backtracking(ticketsNum, usedSum+1, it->first, ticketsMap, path, result);
                it->second++;
                path.pop_back();
            }
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> path = {"JFK"};
        vector<string> result;
        unordered_map<string, map<string, int>> ticketsMap;
        for(int i = 0; i < tickets.size(); i++)
                ticketsMap[tickets[i][0]][tickets[i][1]]++;

        backtracking(tickets.size(), 0, "JFK", ticketsMap, path, result);

        return result;
    }
};

// Solution
class Solution {
private:
    bool backtracking(int ticketsNum, int usedSum, string curPos, unordered_map<string, map<string, int>>& ticketsMap, vector<string>& result){
        if(usedSum == ticketsNum)
            return true;
             
        for(auto it = ticketsMap[curPos].begin(); it != ticketsMap[curPos].end(); it++){
            if(it->second != 0){
                result.push_back(it->first);
                it->second--;
                if(backtracking(ticketsNum, usedSum+1, it->first, ticketsMap, result)) return true;
                it->second++;
                result.pop_back();
            }
        }

        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result = {"JFK"};
        unordered_map<string, map<string, int>> ticketsMap;
        for(int i = 0; i < tickets.size(); i++)
                ticketsMap[tickets[i][0]][tickets[i][1]]++;

        backtracking(tickets.size(), 0, "JFK", ticketsMap, result);

        return result;
    }
};

int main(){

    Solution s;

    return 0;
}