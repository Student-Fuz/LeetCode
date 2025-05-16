#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // key-val, value--index
        unordered_map<int, int> visited;

        for(int i = 0; i < nums.size(); i++){
            if(visited.find(target - nums[i]) != visited.end()){
                return {visited[target-nums[i]], i};
            }
            visited[nums[i]] = i;
        }

        return {};
    }
};

int main() {

    return 0;
}