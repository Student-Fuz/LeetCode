#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 题目描述
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
// 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

// Solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++){
            if(!merged.size() || intervals[i][0] > merged.back()[1]){
                merged.push_back({intervals[i][0], intervals[i][1]});
            }
            else{
                int L = merged.back()[0], R = intervals[i][1];
                merged.push_back({L, R});
            }
        }

        return merged;
    }
};

int main(){

    Solution s;

    return 0;
}