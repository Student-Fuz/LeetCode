#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int startIndex, int len){
        if(subset.size() == len){
            result.push_back(subset);
            return;
        }

        for(int i = startIndex; i < nums.size(); i++){
            // 可剪枝
            subset.push_back(nums[i]);
            backtracking(nums, result, subset, i+1, len);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        for(int i = 0; i <= nums.size(); i++){
            backtracking(nums, result, subset, 0, i);
        }

        return result;
    }
};

int main() {

    return 0;
}