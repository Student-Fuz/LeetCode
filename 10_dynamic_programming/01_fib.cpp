#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/fibonacci-number/

// Solution
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        vector<int> result(2);
        result[0] = 0;
        result[1] = 1;
        for(int i = 2; i < n+1; i++){
            result[i%2] = result[0] + result[1];
        }
        return result[n%2];
    }
};
int main(){

    Solution s;

    return 0;
}