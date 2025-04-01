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
        string str;
        string str_mul;
        string num;
        int num_int;
        vector<char> char_stack;

        for(const char char_s : s){
            if(char_s == ']'){
                while(char_stack.back() != '['){
                    str.push_back(char_stack.back());
                    char_stack.pop_back();
                }
                char_stack.pop_back();

                while((!char_stack.empty()) && char_stack.back() >= '0' && char_stack.back() <= '9'){
                    num.push_back(char_stack.back());
                    char_stack.pop_back();
                }
                reverse(num.begin(), num.end());
                num_int = stoi(num);

                for(int i = 0; i < num_int; i++){
                    str_mul += str;
                }
                
                reverse(str_mul.begin(), str_mul.end());
                for(int i = 0; i < str_mul.size(); i++){
                    char_stack.push_back(str_mul[i]);
                    
                }
                str_mul = "";
                str = "";
                num = "";
                num_int = 0;
            }
            else{
                char_stack.push_back(char_s);
            }

        }

        string result;

        for(int i = 0; i < char_stack.size(); i++){
            result.push_back(char_stack[i]); 
        }
        

        return result;

    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}