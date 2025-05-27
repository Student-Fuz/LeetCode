#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for(int i = 0; i < tokens.size(); i++){
           if(tokens[i] == "+"){
                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();
                int result = op1 + op2;
                nums.push(result);
           }else if(tokens[i] == "-"){
                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();
                int result = op2 - op1;
                nums.push(result);
           }else if(tokens[i] == "*"){
                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();
                int result = op1 * op2;
                nums.push(result);
           }else if(tokens[i] == "/"){
                int op1 = nums.top();
                nums.pop();
                int op2 = nums.top();
                nums.pop();
                int result = op2 / op1;
                nums.push(result);
           }else{
                nums.push(stoi(tokens[i]));
           }
        }

        return nums.top();
    }
};

int main() {

    return 0;
}