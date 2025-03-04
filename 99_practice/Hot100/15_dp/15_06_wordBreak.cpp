#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/word-break/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string> strSet;
        strSet.insert("");

        string subStr = "";
        for(int i = 0; i < s.size(); i++){
            subStr.push_back(s[i]);
            for(int j = 0; j < wordDict.size(); j++){
                for(const string& str : strSet){
                    if(str+wordDict[j] == subStr){

                    }
                }
            }
        }


        return;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
