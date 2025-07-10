#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/add-strings/description/

class Solution {
public:
    string addStrings(string num1, string num2) {
        bool carry = false;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int maxSize = max(num1.size(), num2.size());
        string result;
        for(int i = 0; i < maxSize; i++){
            int cur = 0;
            if(i < num1.size()) cur += num1[i] - '0';
            if(i < num2.size()) cur += num2[i] - '0';
            if(carry) cur += 1;
            if(cur >= 10) carry = true;
            else carry = false;
            cur = cur % 10;
            result.push_back(cur + '0');
        }

        if(carry) result.push_back('1');
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {

    return 0;
}