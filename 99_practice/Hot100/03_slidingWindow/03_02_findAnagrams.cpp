#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/?envType=study-plan-v2&envId=top-100-liked

// Solution
// 哈希表版本
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};

        unordered_map<char, int> charMap_p;
        unordered_map<char, int> charMap_s;
        bool flag = true;

        vector<int> res;

        for(int i = 0; i < p.size(); i++){
            charMap_p[p[i]]++;
            charMap_s[s[i]]++;
        }

        charMap_s[s[p.size()-1]]--;
        for(int i = 0; i < s.size() - p.size() + 1; i++){
            flag = true;
            charMap_s[s[i+p.size()-1]]++;
            for(auto [char_p, freq] : charMap_p){
                if(charMap_s.find(char_p) == charMap_s.end() || charMap_s[char_p] != freq){
                    flag = false;
                    break;
                }    
            }
            if(flag)
                res.push_back(i);
            charMap_s[s[i]]--;
        }

        return res;
    }
};

// 数组版本
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};

        vector<int> charMap_p(26, 0);
        vector<int> charMap_s(26, 0);

        bool flag = true;

        vector<int> res;

        for(int i = 0; i < p.size(); i++){
            charMap_p[p[i] - 'a']++;
            charMap_s[s[i] - 'a']++;
        }

        charMap_s[s[p.size()-1] - 'a']--;
        for(int i = 0; i < s.size() - p.size() + 1; i++){
            flag = true;
            charMap_s[s[i+p.size()-1] - 'a']++;
            for(int j = 0; j < 26; j++){
                if(charMap_p[j] != charMap_s[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res.push_back(i);
            charMap_s[s[i] - 'a']--;
        }

        return res;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}