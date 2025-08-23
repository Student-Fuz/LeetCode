#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/power-of-three/?envType=daily-question&envId=2025-08-21

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n >= 3){
            if(n % 3)
                return false;
            n /= 3;
        }
        if(n != 1)
            return false;
        return true;
    }
};

int main() {

    return 0;
}