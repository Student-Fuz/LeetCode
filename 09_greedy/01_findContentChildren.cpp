#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 题目描述


// Solution
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;
        int i = 0;  // 用来遍历饼干数组
        int j = 0;  // 用来遍历孩子数组

        // 使用双指针方法：i 指向饼干数组，j 指向孩子数组
        while (i < s.size() && j < g.size()) {
            // 如果当前饼干满足当前孩子
            if (s[i] >= g[j]) {
                res++;  // 一个孩子被满足
                j++;    // 让孩子数组向前推进
            }
            i++;  // 即使饼干没有满足孩子，也要继续遍历下一个饼干
        }

        return res;
    }
};


int main(){

    Solution s;

    return 0;
}