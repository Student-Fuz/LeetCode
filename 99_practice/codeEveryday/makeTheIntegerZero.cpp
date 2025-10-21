#include <bits/stdc++.h>
using namespace std;

int bitCnt(long long n){
    int cnt = 0;
    while(n){
        n &= n-1;
        cnt++;
    }
    return cnt;
}

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while (true) {
            long long x = num1 - static_cast<long long>(num2) * k;
            if (x < k) {
                return -1;
            }
            if (k >= bitCnt(x)) {
                return k;
            }
            // if (k >= __builtin_popcountll(x)) {
            //     return k;
            // }
            k++;
        }
    }
};


int main() {

    return 0;
}