#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/coin-change/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount+1, 0);
        // key--price; val--nums
        unordered_map<int, int> priceMap;
        for(int i = 1; i < amount; i++){
            // 在过去的数组中查找组合
            for(){

            }
        }

        return res[amount];
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
