#include <iostream>
#include <string>
#include <array>

using namespace std;

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词
// 示例 1:

// 输入: s = "anagram", t = "nagaram"
// 输出: true
// 示例 2:

// 输入: s = "rat", t = "car"
// 输出: false

int main(){


    return 0;
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 26> record_array;
        for(auto char_s : s){
            record_array[char_s - 'a'] += 1;
        }

        for(auto char_t :t){
            record_array[char_t - 'a'] -= 1;
        }

        for(int i = 0; i < 26; i++){
            if(record_array[i] != 0)
                return false;
        }

        return true;
    }
};