#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-69-number/?envType=daily-question&envId=2025-08-17

// m1: 字符串
class Solution {
public:
    int maximum69Number (int num) {
        int res = 0;
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        res = stoi(s);
        return res;
    }
};

// m2: 

int main() {

    return 0;
}