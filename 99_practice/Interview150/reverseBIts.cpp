#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;       // 左移一位腾位置
            result |= (n & 1);  // 取 n 的最低位加到 result
            n >>= 1;            // n 右移一位
        }
        return result;
    }
};


int main() {

    return 0;
}