#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/monotone-increasing-digits/description/

// 复习 TODO
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);

        int mark = strNum.size();
        for(int i = strNum.size()-1; i >= 1; i--){
            if(strNum[i] < strNum[i-1]){
                strNum[i-1]--;
                mark = i;
            }
        }

        for(int i = mark; i < strNum.size(); i++){
            strNum[i] = '9';
        }

        return stoi(strNum);
    }
};

// 贪心
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n < 10) return n;
        string strNum = to_string(n);

        // char preNum = strNum.back();
        int mark = strNum.size()-1;
        for(int i = strNum.size()-2; i >= 0; i--){
            if(strNum[i] > strNum[i+1]){
                strNum[i]--;
                mark = i;
            }
        }

        // int result = 0;
        // for(int i = 0; i < strNum.size(); i++){
        //     result *= 10;
        //     result += strNum[i] - '0';
        // }

        for(int i = mark+1; i < strNum.size(); i++){
            strNum[i] = '9';
        }

        return stoi(strNum);
    }
};

// 暴力
class Solution {
private:
    bool isMonotoneInc(int n){
        int preDigit = n%10;
        while(n != 0){
            int digit = n%10;
            n /= 10;
            if(digit > preDigit)
                return false;
            preDigit = digit;
        }
        return true;
    }

public:
    int monotoneIncreasingDigits(int n) {
        for(int i = n; i >= 0; i--){
            if(isMonotoneInc(i))
                return i;
        }
        return 0;
    }
};


int main() {

    return 0;
}
