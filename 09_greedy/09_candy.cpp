#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/candy/solutions/533150/fen-fa-tang-guo-by-leetcode-solution-f01p/

// 注意：
// 输入：ratings = [1,2,2]
// 输出：4
// 解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
//      第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        }

        for(int i = ratings.size()-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1]+1);
        }

        int result = 0;
        for(auto candy: candies) result += candy;
        return result;
    }
};

int main() {

    return 0;
}