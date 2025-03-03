#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cmath>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/perfect-squares/description/?envType=study-plan-v2&envId=top-100-liked

// Solution
// dp1
class Solution {
public:
    int numSquares(int n) {
        vector<int> minSums(n+1, 0);
        minSums[1] = 1;

        for(int i = 1; i <= n; i++){
            int minSum = i;
            for(int j = 1; j <= pow(i, 0.5); j++){
                minSum = min(1 + minSums[i - j*j], minSum);
            }
            minSums[i] = minSum;
        }
        return minSums.back();
    }
};

// dp1-1
class Solution {
public:
    int numSquares(int n) {
        vector<int> minSums(n+1, 0);
        minSums[1] = 1;

        for(int i = 1; i <= n; i++){
            int minSum = i;
            for(int j = 1; j <= pow(i, 0.5); j++){
                minSum = min(minSums[i - j*j], minSum);
            }
            minSums[i] = minSum + 1;
        }
        return minSums.back();
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}