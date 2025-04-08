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
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(const auto &interval : intervals){
            if(result.back()[0] <= interval[0] && interval[0] <= result.back()[1])
                result.back()[1] = max(result.back()[1], interval[1]);
            else
                // Q: 这里的interval是深拷贝还是浅拷贝？
                // A: 这是深拷贝（更准确地说，是值拷贝）
                result.push_back(interval);
        }

        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}