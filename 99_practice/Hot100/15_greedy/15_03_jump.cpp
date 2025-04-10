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

// 这道题是典型的贪心算法，通过局部最优解得到全局最优解。

// Solution
// m1: 反向查找
// 反向找能到到达当前点最远的上一个点
class Solution {
public:
    int jump(vector<int>& nums) {
        int position = nums.size() - 1;
        int step = 0;

        while(position > 0){
            for(int i = 0; i < nums.size(); i++){
                if(i + nums[i] >= position){    
                    position = i;
                    step++;
                    break;
                }
            }
        }
        
        return step;
    }
};

// m2: 正向查找
// 在能到达的最远点更新步数
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0;
        int end = 0;
        int step = 0;

        for(int i = 0; i < nums.size()-1; i++){
            if(i <= maxPos){
                maxPos = max(maxPos, i+nums[i]);
                if(i == end){
                    end = maxPos;
                    step++;
                }
            }
        }

        return step;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}