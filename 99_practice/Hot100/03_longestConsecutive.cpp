#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/two-sum/?envType=study-plan-v2&envId=top-100-liked

// 时间复杂度O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;

        for(const int& num : nums){
            nums_set.insert(num);
        }
            
        int maxLength = 0;

        for(const int& num : nums_set){
            // 从最小值开始
            if(!nums_set.count(num-1)){
                int curNum = num;
                int curLength = 1;
                while(nums_set.count(curNum+1)){
                    curNum += 1;
                    curLength += 1;
                }
                maxLength = max(maxLength, curLength);
            }
        }

        return maxLength;
    }
};

// 标准答案
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> num_set;
            for (const int& num : nums) {
                num_set.insert(num);
            }
    
            int longestStreak = 0;
    
            for (const int& num : num_set) {
                if (!num_set.count(num - 1)) {
                    int currentNum = num;
                    int currentStreak = 1;
    
                    while (num_set.count(currentNum + 1)) {
                        currentNum += 1;
                        currentStreak += 1;
                    }
    
                    longestStreak = max(longestStreak, currentStreak);
                }
            }
    
            return longestStreak;           
        }
    };

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}