#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> result_set;

        for(const auto& num1 : nums1)
            set1.insert(num1);

        for(const auto& num2 : nums2){
            if(set1.count(num2) != 0 && result_set.count(num2) == 0)
                result_set.insert(num2);
        }

        vector<int> result;
        for(const auto& num : result_set)
            result.push_back(num);
        
        return result;
    }
};

int main() {

    return 0;
}