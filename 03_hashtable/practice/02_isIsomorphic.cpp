#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述


// Solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> char_map_s;
        unordered_map<char, int> char_map_t;

        for(int i = 0; i < s.size(); i++){
            if(char_map_s.find(s[i]) != char_map_s.end() && char_map_t.find(t[i]) != char_map_t.end()){
                if(char_map_s[s[i]] != char_map_t[t[i]])
                    return false;
            }
            else if(char_map_s.find(s[i]) == char_map_s.end() && char_map_t.find(t[i]) == char_map_t.end())
                char_map_s[s[i]] = char_map_t[t[i]] = char_map_s.size();
            else
                return false;
        }

        return true;

    }
};

int main(){

    Solution s;

    return 0;
}