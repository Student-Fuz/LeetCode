#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/unique-paths/description/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 数学：C(n-1)/(m-1+n-1)
        long res = 1;
        long j = m;
        long k = 1;
        for(int i = 0; i < n-1; i++){
            res *= j;
            res /= k;
            j++;
            k++;
        }
        return (int)res;
    }
};

int main() {

    return 0;
}