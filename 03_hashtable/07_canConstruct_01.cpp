#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq_r(26, 0);
        vector<int> freq_m(26, 0);

        for(const auto& char_s : ransomNote){
            freq_r[char_s - 'a']++;
        }

        for(const auto& char_m : magazine){
            freq_m[char_m - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq_r[i] > freq_m[i])
                return false;
        }

        return true;
    }
};

int main() {

    return 0;
}