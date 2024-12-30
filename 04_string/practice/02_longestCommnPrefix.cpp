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
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;

        for(int i = 0; i < strs[0].size(); i++){
            prefix.push_back(strs[0][i]);
            for(const auto& str : strs){
                if(prefix != str.substr(0, i+1)){
                    prefix.pop_back();
                    return prefix;
                }
            }
        }

        return prefix;
    }
};

int main(){

    Solution s;

    return 0;
}