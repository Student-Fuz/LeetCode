#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/generate-parentheses/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
private:
    // to generate len = 2n
    void backtracking(int n, vector<vector<string>>){

        for(int i = 0; 2 * i + 1 < n; i++){
            for(){

            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        
    }
};

// Solution
class Solution {
private:
    void backtracking(int left, int right, string str, vector<string>& result){
        if(left == 0 && right == 0){
            result.push_back(str);
            return;
        }

        if(left == right){
            str.push_back('(');
            backtracking(left - 1, right, str, result);
            str.pop_back();
        }
        else{
            if(left > 0){
                str.push_back('(');
                backtracking(left - 1, right, str, result);
                str.pop_back();
            }
            str.push_back(')');
            backtracking(left, right-1, str, result);
            str.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> result;
        backtracking(n, n, "", result);
        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}