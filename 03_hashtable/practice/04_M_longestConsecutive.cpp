#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

// Solution
//  class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         // key--bound(low/up)(2 sides open) val--bounds of two sides
//         unordered_map<int, pair<int, int>> consecutives;
//         int max_length = 0;

//         for(auto num : nums){
//             if(consecutives.find(num) != consecutives.end()){
//                 if(num == consecutives[num].first){
//                     int new_lower = consecutives[num].first-1;
//                     int old_upper = consecutives[num].second;
//                     consecutives[new_lower] = {new_lower, old_upper};
//                     consecutives[old_upper] = {new_lower, old_upper};
//                     consecutives.erase(num);
//                 }
//                 else{
//                     int old_lower = consecutives[num].first;
//                     int new_upper = consecutives[num].second+1;
//                     consecutives[old_lower] = {old_lower, new_upper};
//                     consecutives[new_upper] = {old_lower, new_upper};
//                     consecutives.erase(num);
//                 }
//             }
//             else{
//                 consecutives[num-1] = {num-1, num+1};
//                 consecutives[num+1] = {num-1, num+1};
//             }
//         }

//         for(auto [bound, section] : consecutives){
//             int lower = section.first;
//             int upper = section.second;
//             max_length = max(upper-lower-1, max_length);
//             // consecutives.erase(lower);
//             // consecutives.erase(upper);
//         }
//         return max_length;
//     }
// };

// 假设数组无重复元素
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // key--bound(low/up)(left closed, right open) val--bounds of two sides
        unordered_set<int> numset;
        unordered_map<int, pair<int, int>> consecutives;
        int max_length = 0;
        for(auto num : nums){
            // 重复数据
            if(numset.find(num) != numset.end())
                continue;
            else
                numset.insert(num);
            if(consecutives.find(num) != consecutives.end()){
                // update upper bound
                int old_lower = consecutives[num].first;
                int old_upper = consecutives[num].second;
                int new_upper = old_upper+1;
                // connect two section
                if(consecutives.find(new_upper) != consecutives.end()){
                    int old_lower_1 = new_upper;
                    int new_upper_1 = consecutives[new_upper].second;
                    new_upper = new_upper_1;
                    // 删除下区间上边界
                    consecutives.erase(old_upper);
                    // 删除上区间下边界
                    consecutives.erase(old_lower_1);
                }
                consecutives[old_lower] = {old_lower, new_upper};
                consecutives[new_upper] = {old_lower, new_upper};
            }
            else{
                int new_lower = num;
                int new_upper = num+1;
                // connect two section
                if(consecutives.find(new_upper) != consecutives.end()){
                    int old_lower_1 = new_upper;
                    int new_upper_1 = consecutives[new_upper].second;
                    new_upper = new_upper_1;
                    // 删除上区间下边界
                    consecutives.erase(old_lower_1);
                }
                consecutives[new_lower] = {new_lower, new_upper};
                consecutives[new_upper] = {new_lower, new_upper};
            }
        }

        for(auto [bound, section] : consecutives){
            int lower = section.first;
            int upper = section.second;
            max_length = max(upper-lower, max_length);
            // consecutives.erase(lower);
            // consecutives.erase(upper);
        }
        return max_length;
    }
};

// 哈希表标准解法
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

    Solution s;

    vector<int> vec_tst = {4,1,3,2};

    s.longestConsecutive(vec_tst);

    return 0;
}