#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/alice-and-bob-playing-flower-game/description/?envType=daily-question&envId=2025-08-29

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long even_n = n/2, odd_n = n/2+n%2, even_m = m/2, odd_m = m/2+m%2;
        return even_n*odd_m + even_m*odd_n;
    }
};

int main() {

    return 0;
}