#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150

// 优化 TODO？
class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        string result;
        for(int i = 0; i < max(a.size(), b.size()); i++){
            if(i < a.size() && i < b.size()){
                int sum = (a[a.size()-1-i] + b[b.size()-1-i] + carry - 2*'0');
                int bit = sum%2;
                carry = sum/2;
                result.push_back(bit+'0');
            }
            else if(i < a.size()){
                int sum = (a[a.size()-1-i]  + carry - '0');
                int bit = sum%2;
                carry = sum/2;
                result.push_back(bit+'0');
            }
            else{
                int sum = (b[b.size()-1-i]  + carry - '0');
                int bit = sum%2;
                carry = sum/2;
                result.push_back(bit+'0');
            }
        }
        if(carry) result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {

    return 0;
}