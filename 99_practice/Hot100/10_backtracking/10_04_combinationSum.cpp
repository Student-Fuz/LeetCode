#include <bits/stdc++.h>
using namespace std;

// 如果问题要求的是计数（如“有多少种组合”），则可以用动态规划（DP），时间复杂度为 O(n * target)，远优于回溯的指数级复杂度。
// 但对于列出所有解，回溯仍然是较优的选择。；


// 效率低 TODO
// 小技巧：将vector<int>转化为string去重
class Solution {
private:
    void dfs(vector<int>& candidates, int sum, int target, unordered_set<string>& result_set, vector<int>& comb, vector<vector<int>>& result){
        if(sum > target) return;

        if(sum == target){
            string result_s;
            // 此处必须使用副本进行排序去重
            // 因为之后的递归会弹出最后元素
            vector<int> comb_copy = comb;
            sort(comb_copy.begin(), comb_copy.end());
            for(const auto& int_c : comb_copy){
                result_s += to_string(int_c) + ",";
            }
            if(result_set.count(result_s) == 0){
                result_set.insert(result_s);
                result.push_back(comb_copy);
            }
                
        }

        for(int i = 0; i < candidates.size(); i++){
            comb.push_back(candidates[i]);
            dfs(candidates, sum+candidates[i], target, result_set, comb, result);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        unordered_set<string> result_set;

        dfs(candidates, 0, target, result_set, comb, result);
        return result;
    }
};


// 优雅版
class Solution {
private:
    void dfs(vector<int>& candidates, int start, int sum, int target, vector<int>& comb, vector<vector<int>>& result){
        if(sum > target) return;

        if(sum == target){
            result.push_back(comb);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            comb.push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i], target, comb, result); // 传入 i 保持顺序
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        dfs(candidates, 0, 0, target, comb, result);
        return result;
    }
};
    


int main() {

    return 0;
}