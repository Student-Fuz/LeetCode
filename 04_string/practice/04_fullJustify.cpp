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
                line_len = line_len + words[i].size()+1;
                line_v.push_back(words[i]);
            }
            // 1. 非最后一行
            else{
                // 1.1 不止一个单词
                if(line_v.size() != 1){ 
                    int sum_spaces = maxWidth - line_len + line_v.size();
                    // 平均空格
                    int num_spaces_avg = sum_spaces/(line_v.size()-1?line_v.size()-1:1);
                    int num_extra_spaces = sum_spaces%(line_v.size()-1?line_v.size()-1:1);
                    // 多余空格置于前num_extra_spaces单词之后
                    for(int i = 0; i < num_extra_spaces; i++){
                        line_s += line_v[i];
                        for(int j = 0; j < num_spaces_avg+1; j++)
                            line_s.push_back(' ');
                    }
                    for(int k = num_extra_spaces; k < line_v.size() - 1; k++){
                        line_s += line_v[k];
                        for(int l = 0; l < num_spaces_avg; l++)
                            line_s.push_back(' ');
                    }  
                    // 最后一个单词
                    line_s += line_v.back();
                }
                // 1.2 只有一个单词
                else{
                    line_s += line_v[0];
                    line_len = line_s.size();
                    for(int i = 0; i < maxWidth - line_len; i++)
                        line_s.push_back(' ');
                }
                ret.push_back(line_s);
                line_s.clear();
                line_v.clear();
                line_len = 0;

                line_len = line_len + words[i].size()+1;
                line_v.push_back(words[i]);
            } 
        }
        // 2. 最后一行
        for(int i = 0; i < line_v.size()-1; i++){
            line_s += (line_v[i]+ " ");
        }
        line_s += (line_v.back());
        line_len = line_s.size();
        for(int i = 0; i < maxWidth - line_len; i++)
            line_s.push_back(' ');

        ret.push_back(line_s);
        return ret;
    }
};

int main(){

    Solution s;

    vector<string> input = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};

    for(auto str : s.fullJustify(input, 20))
        cout << str;
    return 0;
}