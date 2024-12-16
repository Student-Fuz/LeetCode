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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 0;

        vector<int> unReached;
        vector<string> cur = {beginWord};
        vector<string> next;

        // 未到达的地点
        for(int i = 0; i < wordList.size(); i++){
            unReached.push_back(i);
        }

        do{
            length++;
            for(int i = 0; i < cur.size(); i++){
                int slow = 0;
                for(int  fast = 0; fast < unReached.size(); fast++){
                    if(canConvert(cur[i], wordList[unReached[fast]])){
                        if(wordList[unReached[fast]] == endWord)
                            return length+1;
                        next.push_back(wordList[unReached[fast]]);
                    }
                    else
                        unReached[slow++] = unReached[fast];
                }
                unReached.resize(slow);
            }
            cur.clear();
            cur.swap(next);
        }
        while(!cur.empty());

        return 0;
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

// 优化
// 1. 使用
// cur.clear();
// cur.swap(next);
// 不是用这样的交换方式
// 2. 剪去无法继续进行下去的节点
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 0;

        vector<int> unReached;

        vector<vector<string>> step = {{}, {beginWord}};

        // 未到达的地点
        for(int i = 0; i < wordList.size(); i++){
            unReached.push_back(i);
        }

        do{
            length++;
            for(int i = 0; i < step[length%2].size(); i++){
                int slow = 0, fast = 0;
                for(; fast < unReached.size(); fast++){
                    if(canConvert(step[length%2][i], wordList[unReached[fast]])){
                        if(wordList[unReached[fast]] == endWord)
                            return length+1;
                        step[(length+1)%2].push_back(wordList[unReached[fast]]);
                    }
                    else
                        unReached[slow++] = unReached[fast];
                }
                unReached.resize(slow);
            }
            step[length%2].clear();
        }
        while(!step[(length+1)%2].empty());

        return 0;
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

int main(){

    Solution s;

    return 0;
}