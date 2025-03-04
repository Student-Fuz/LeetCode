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
// 超时
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // key--price; val--num
        unordered_map<int, int> priceMap;

        priceMap[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            priceMap[coins[i]] = 1;
        }

        for(int i = 1; i <= amount; i++){
            // 在过去的数组中查找组合
            int minNum = INT_MAX;
            for(auto& [price, num] : priceMap){
                if(priceMap.find(i - price) != priceMap.end()){
                    minNum = min(minNum, priceMap[price] + priceMap[i - price]);
                }
            }
            if(minNum != INT_MAX)
                priceMap[i] = minNum;
        }

        if(priceMap.find(amount) != priceMap.end())
            return priceMap[amount];
        else    
            return -1;
    }
};

// dp优化
// 最新的值只能是之前值加一枚硬币
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // key--price; val--num
        unordered_map<int, int> priceMap;

        priceMap[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            priceMap[coins[i]] = 1;
        }

        for(int i = 1; i <= amount; i++){
            // 在过去的数组中查找组合
            int minNum = INT_MAX;
            for(int j = 0; j < coins.size(); j++){
                if(priceMap.find(i - coins[j]) != priceMap.end()){
                    minNum = min(minNum, priceMap[i - coins[j]]);
                }
            }
            if(minNum != INT_MAX)
                priceMap[i] = minNum+1;
        }

        if(priceMap.find(amount) != priceMap.end())
            return priceMap[amount];
        else    
            return -1;
    }
};

// 回溯枚举 TODO


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
