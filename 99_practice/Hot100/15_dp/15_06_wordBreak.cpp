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
// https://leetcode.cn/problems/word-break/?envType=study-plan-v2&envId=top-100-liked

// 超时
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string> strSet;
        strSet.push_back("");

        string subStr = "";
        for(int i = 0; i < s.size(); i++){
            subStr.push_back(s[i]);
            for(int j = 0; j < wordDict.size(); j++){
                int setSize = strSet.size();
                for(int k = 0; k < setSize; k++){
                    string newString = strSet[k] + wordDict[j];
                    if(newString == subStr){
                        strSet.push_back(newString);
                    }
                }
            }
        }
        return strSet.back() == s;
    }
};

// 剪枝
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string> strSet;
        strSet.push_back("");

        string subStr = "";
        for(int i = 0; i < s.size(); i++){
            subStr.push_back(s[i]);
            for(int j = 0; j < wordDict.size(); j++){
                int setSize = strSet.size();
                for(int k = 0; k < setSize; k++){
                    // 字符串长度检查
                    if(strSet[k].size() + wordDict[j].size() != subStr.size())
                        continue;
                    string newString = strSet[k] + wordDict[j];
                    if(newString == subStr){
                        strSet.push_back(newString);
                    }
                }
            }
        }
        return strSet.back() == s;
    }
};

// 哈希表
// 字符串的减法：substr()函数
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> strSet;

        for(int i = 0; i < wordDict.size(); i++)
            strSet.insert(wordDict[i]);

        for(int i = 1; i < s.size()+1; i++){
            for(int j = 0; j < wordDict.size(); j++){
                // 长度检查
                if(i > wordDict[j].size()){
                    if(strSet.find(s.substr(i, i - wordDict[j].size())) != strSet.end() && ){

                    }
                }
            }
        }

        return ;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();

        int maxLen = 0;
        for (auto word: wordDict) {
            wordDictSet.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = (i - maxLen>0)?i - maxLen:0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
    

int main(){

    // Solution s;

    string s = "hello, world!";
    cout << s.substr(0,1) << endl;

    return 0;
}
