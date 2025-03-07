#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/description/?envType=study-plan-v2&envId=top-100-liked

// Solution
// 双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        for (int i = 0; i <= high; ) {
            if (nums[i] == 0) {
                // 从前面交换到索引i的数不会是2，无需再次判断
                // 所以i++
                swap(nums[i], nums[low]);
                low++;
                i++;
            } else if (nums[i] == 2) {
                // 从后面交换到索引i的数可能是0，需要再次判断
                // 所以没有i++
                swap(nums[i], nums[high]);
                high--;
            } else {
                i++;
            }
        }
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}