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
    int lengthOfLastWord(string s) { 
        vector<string> string_buffer = split(s);
        return string_buffer.back().length();
    }

    vector<string> split(const string& s){
        vector<string> result;

        string str_buffer;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(!str_buffer.empty()){
                    result.push_back(str_buffer);
                    str_buffer.clear();
                }
            }
            else                
                str_buffer.push_back(s[i]);
        }
        if(!str_buffer.empty())
            result.push_back(str_buffer);

        return result;
    }
};

int main(){

    Solution s;

    string str = "hello, world"; 
    for(auto sub_s : s.split(str))
        cout << sub_s << endl;

    return 0;
}