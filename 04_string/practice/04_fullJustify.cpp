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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        vector<string> line_v;
        string line_s;
        int line_len = 0;
        for(int i = 0; i < words.size(); i++){
            if(line_len + words[i].size() <= maxWidth){
                line_len = linelen + words[i].size()+1;
                line_v.push_back(words[i]);
            }
            else if(line_v.size() != 0){ //非最后一行
                line_s += line_v[0];
                // 平均空格
                int num_spaces_avg = maxWidth - line_len/(line_v.size()-1?line_v.size()-1:1);
                // 多余空格置于第一个单词之后
                for(int i = 0; i < num_spaces_avg + maxWidth%(line_v.size()-1); i++)
                    line_s.push_back(' ');
                for(int i = 1; i < line_v.size() - 1; i++){
                    line_s += line_v[i];
                    for(int j = 0; j < num_spaces_avg; j++)
                        line_s.push_back(' ');
                }  
                // 最后一个单词
                if(line_v.size() != 1)
                    line_s += line_s[line_v.size()-1];
                ret.push_back(line_s);
                line_s.clear();
                line_v.clear();
            }
        }

        return ret;
    }
};

int main(){

    Solution s;

    return 0;
}