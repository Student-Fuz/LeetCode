#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    string decodeString(string s) {
        string result;
        string result_1;
        vector<char> char_stack;

        for(const char char_s : s){
            if(char_s == ']'){
                while(char_stack.back() != '['){
                    result.push_back(char_stack.back());
                    char_stack.pop_back();
                }
                char_stack.pop_back();
                for(int i = 0; i < char_stack.back(); i++){
                    result_1 += result;
                }
                
            }

        }

        return result_1;

    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}