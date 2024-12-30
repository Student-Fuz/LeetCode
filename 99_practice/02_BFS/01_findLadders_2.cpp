#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int length = 0;

        vector<int> unReached;
        unordered_set<int> reached;

        // key--current position; key--paths this way
        unordered_map<string, vector<vector<int>>> cur = {{beginWord, {{}}}};
        unordered_map<string, vector<vector<int>>> next;

        vector<vector<string>> result_paths;

        // 未到达的地点
        for(int i = 0; i < wordList.size(); i++){
            unReached.push_back(i);
        }

        do{
            length++;
            for(auto [curWord, paths] : cur){
                for(int j = 0; j < unReached.size(); j++){
                    string next_word = wordList[unReached[j]];
                    // 可以到达unReached[j]
                    if(canConvert(curWord, next_word)){ 
                        for(auto path : paths){
                            path.push_back(unReached[j]);
                            next[next_word].push_back(path);
                        }  
                    }
                } 
            }
            int i = 0;
            for(int j = 0; j < unReached.size(); j++){
                if(next.find(wordList[unReached[j]]) == next.end())
                    unReached[i++] = unReached[j]; 
            }

            unReached.resize(i);

            // 如果到了endWord
            if(next.find(endWord) != next.end()){
                for(auto& path :next[endWord]){
                    vector<string> path_s = {beginWord};
                    for(auto& step : path){
                        path_s.push_back(wordList[step]);
                    }
                    result_paths.push_back(path_s);
                }
                return result_paths;
            }

                    
            // 交换 cur 与 next   
            cur.clear();
            cur.swap(next);
        }
        while(!cur.empty());

        return {};
    }
    
    bool canConvert(string s1, string s2){
        if(s1.size() != s2.size())
            return false;
        int diffCharNum = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i])
                if(++diffCharNum > 1)
                    return false;
        }
        if(diffCharNum == 1)
            return true;
        else
            return false;
    }
};

// Solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        
    }
};

int main(){

    Solution s;

    return 0;
}