#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/min-cost-climbing-stairs/

// Solution
// 时间复杂度O(N)
// 空间复杂度O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // if(cost.size() <= 1)
        //     return 0;

        vector<int> cost_sum(cost.size()+1);
        cost_sum[0] = 0;
        cost_sum[1] = 0;

        for(int i = 2; i < cost.size()+1; i++)
            cost_sum[i] = min((cost_sum[i-1]+cost[i-1]), (cost_sum[i-2]+cost[i-2]));

        return cost_sum[cost.size()];
    }
};

// 时间复杂度O(N)
// 空间复杂度O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // if(cost.size() <= 1)
        //     return 0;

        vector<int> cost_sum(2);
        cost_sum[0] = 0;
        cost_sum[1] = 0;

        for(int i = 2; i < cost.size()+1; i++)
            cost_sum[i%2] = min((cost_sum[i%2]+cost[i-2]), (cost_sum[(i-1)%2]+cost[i-1]));

        return cost_sum[cost.size()%2];
    }
};

int main(){

    Solution s;

    return 0;
}