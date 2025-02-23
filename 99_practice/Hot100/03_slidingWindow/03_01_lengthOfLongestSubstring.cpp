#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-100-liked

// Solution
// m2: 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;

        int maxLength = 0;

        // 子串区间 左闭右开 [i, end)
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            if(i != 0) char_set.erase(s[i-1]);
            for(int j = end; j < s.size(); j++){
                if(!char_set.count(s[j])){
                    maxLength = max(maxLength, j - i + 1);
                    char_set.insert(s[j]);
                    // maxLength = max(maxLength, (int)char_set.size());
                }
                else{
                    end = j;
                    break;
                }
            }
        }

        return maxLength;

    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}