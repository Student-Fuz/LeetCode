#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/power-of-four/description/?envType=daily-question&envId=2025-08-15

class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n >= 4){
            if(n % 4) return false;
            n /= 4;
        }
        return n == 1 ? true : false;
    }
};

int main() {

    return 0;
}