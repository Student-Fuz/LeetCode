#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。


// 暴力解法
// 时间复杂度O(n^2)
// 超出时间限制
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i+1; j < prices.size(); j++){
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        if(maxProfit > 0)
            return maxProfit;
        else
            return 0;
    }
};

// 标准答案
// 每次都假设是今天卖出，然后求今天之前的历史最低点。而这个历史最低点并不需要额外遍历，而是每天考虑的时候顺带记录的。因此时间复杂度还是O(N)而不是O(N^2)。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int price : prices){
            maxProfit = std::max(maxProfit, price - minPrice);
            minPrice = std::min(price, minPrice);
        }

        return maxProfit;
    }
};


int main(){

    Solution s;

    return 0;
}