#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit = prices[0];
        int maxProfit = INT_MIN;

        for(int price : prices){
            maxProfit = max(maxProfit, price - minProfit);
            minProfit = min(minProfit, price);
        }

        return maxProfit;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}