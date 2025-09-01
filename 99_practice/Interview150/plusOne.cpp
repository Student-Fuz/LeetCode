#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            int cur = digits[i] + carry;
            carry = cur / 10;
            cur = cur % 10;
            result.push_back(cur);
        }
        if(carry) result.push_back(1);
        reverse(result.begin(), result.end());

        return result;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long w = 1;
        long long r = 0;
        for(int i = digits.size()-1; i >= 0; i--){
            r += digits[i] * w;
            w *= 10;
        }
        
        r++;
        vector<int> result;
        
        if(r/w) result.push_back(1);
        for(int i = digits.size()-1; i >= 0; i--){
            r %= w;
            w /= 10;
            result.push_back(r/w);
        }

        return result;
    }
};

int main() {

    return 0;
}