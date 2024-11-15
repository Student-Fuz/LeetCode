#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。

// 示例 1：

// 输入：ransomNote = "a", magazine = "b"
// 输出：false
// 示例 2：

// 输入：ransomNote = "aa", magazine = "ab"
// 输出：false
// 示例 3：

// 输入：ransomNote = "aa", magazine = "aab"
// 输出：true

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::array<int, 26> char_arr = {0};

        for(char char_m : magazine)
            char_arr[char_m - 'a'] += 1;

        for(char char_r : ransomNote)
            if(--char_arr[char_r - 'a'] < 0)
                return false;

        return true;
    }
};


int main(){

    Solution s;
    // cout << s.twoSUm(19);
    return 0;
}

