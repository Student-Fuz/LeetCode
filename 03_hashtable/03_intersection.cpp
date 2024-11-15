#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 给你一个字符串数组 words ，
// 请你找出所有在 words 的每个字符串中都出现的共用字符（包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
 

// 示例 1：

// 输入：words = ["bella","label","roller"]
// 输出：["e","l","l"]
// 示例 2：

// 输入：words = ["cool","lock","cook"]
// 输出：["c","o"]


int main(){

    cout << "Hello word!";

    return 0;
}


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        std::unordered_set<int> intersection_set;

        for(auto num2 : nums2){
            // 如果nums1_set找到num2
            if(nums1_set.find(num2) != nums1_set.end())
                intersection_set.insert(num2); 
        }

        std::vector<int> intersection_vec(intersection_set.begin(), intersection_set.end());

        return intersection_vec;
    }
};
