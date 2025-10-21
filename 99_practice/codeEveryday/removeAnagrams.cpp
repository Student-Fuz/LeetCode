#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/find-resultant-array-after-removing-anagrams/?envType=daily-question&envId=2025-10-13

// 移除所有异位词如何？（或对异位词进行分组）
// https://leetcode.cn/problems/group-anagrams/
// 方法一：排序作为hash表的键
// 方法二：计数、以长度为26的数组作为键

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if(words.size() == 0) return {};
        vector<int> char_map(26, 0);
        int size = words[0].size();
        vector<string> r;
        r.push_back(words[0]);
        // 初始化char_map
        for(int i = 0; i < words[0].size(); i++){
            char_map[words[0][i]-'a']++;
        }
        for(int i = 1; i < words.size(); i++){
            vector<int> cur_char_map(26, 0);
            for(int j = 0; j < words[i].size(); j++){
                cur_char_map[words[i][j]-'a']++;
            }
            bool matched = true;
            for(int j = 0; j < 26; j++){
                if(char_map[j] != cur_char_map[j]){
                    matched = false;
                    break;
                }
            }
            if(!matched){
                r.push_back(words[i]);
                char_map = cur_char_map;
            }
        }
        return r;
    }
};

int main() {

    return 0;
}