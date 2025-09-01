#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/number-of-1-bits/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int hammingWeight(int n) {
        int num = 0; 
        for(int i = 0; i < 32; i++){
            num += n & (1);
            n = n >> 1;
        }
        return num;
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        int num = 0;
        while (n) {
            n &= (n - 1); // 每次去掉最低位的1
            num++;
        }
        return num;
    }
};


int main() {

    return 0;
}
