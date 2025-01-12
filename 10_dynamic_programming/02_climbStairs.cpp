#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/climbing-stairs/submissions/591770640/

// Solution
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;

        vector<int> ways(2);
        ways[0] = 1;
        ways[1] = 2;

        for(int i = 3; i < n+1; i++){
            ways[(i-1)%2] = ways[0] + ways[1];
        }

        return ways[(n-1)%2];
    }
};

int main(){

    Solution s;

    return 0;
}