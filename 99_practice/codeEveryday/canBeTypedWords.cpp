#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-number-of-words-you-can-type/?envType=daily-question&envId=2025-09-15

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        string str;
        bool legalFlag = true;
        int cnt = 0;
        unordered_set<char> set;
        for(const auto& ch : brokenLetters){
            set.insert(ch);
        }
        for(int i = 0; i < text.size(); i++){
            if(text[i] == ' '){
                if(legalFlag) cnt++;
                legalFlag = true;
            }
            else{
                if(set.count(text[i])){
                    legalFlag = false;
                }
            }
        }
        if(legalFlag) cnt++;
        return cnt;
    }
};

int main() {

    return 0;
}