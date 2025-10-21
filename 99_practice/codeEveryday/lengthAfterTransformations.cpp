#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/description/?envType=daily-question&envId=2025-10-10


// 快速幂
// 状态转移矩阵 M， 转换t次， 状态转移举矩阵为 M^t
// 对于M^t的计算， 可以采用快速幂的方法加速计算 
static constexpr int L = 26;
static constexpr int mod = 1000000007;

struct Mat {
    Mat() {
        memset(a, 0, sizeof(a));
    }
    Mat(const Mat& that) {
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < L; ++j) {
                a[i][j] = that.a[i][j];
            }
        }
    }
    Mat& operator=(const Mat& that) {
        if (this != &that) {
            for (int i = 0; i < L; ++i) {
                for (int j = 0; j < L; ++j) {
                    a[i][j] = that.a[i][j];
                }
            }
        }
        return *this;
    }

    int a[L][L];
};

Mat operator*(const Mat& u, const Mat& v) {
    Mat w;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            for (int k = 0; k < L; ++k) {
                w.a[i][j] = (w.a[i][j] + (long long)u.a[i][k] * v.a[k][j]) % mod;
            }
        }
    }
    return w;
}

// 单位矩阵
Mat I() {
    Mat w;
    for (int i = 0; i < L; ++i) {
        w.a[i][i] = 1;
    }
    return w;
}

// 矩阵快速幂
Mat quickmul(const Mat& x, int y) {
    Mat ans = I(), cur = x;
    while (y) {
        if (y & 1) {
            ans = ans * cur;
        }
        cur = cur * cur;
        y >>= 1;
    }
    return ans;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Mat T;
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                T.a[(i + j) % 26][i] = 1;
            }
        }
        Mat res = quickmul(T, t);
        int ans = 0;
        vector<int> f(26);
        for (char ch: s) {
            ++f[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = (ans + (long long)res.a[i][j] * f[j]) % mod;
            }
        }
        return ans;
    }
};

// dp
// dp[i][j] 表示 第i次 第j个字母引申出的次数
// 二维写法
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> dp(t, vector<int>(26, 0));
        // int N = 1E9 + 7;
        const int N = 1000000007;
        for(int i = 0; i < 26; i++){
            dp[0][i] = nums[i];
        }
        for(int i = 1; i < t; i++){
            for(int j = 0; j < 26; j++){
                int n = nums[j];
                for(int k = 1; k <= n; k++){
                    dp[i][j] += dp[i-1][(j+k)%26];
                    dp[i][j] %= N;
                }
            }
        }
        int r = 0;
        for(int i = 0; i < s.size(); i++){
            r += dp[t-1][s[i]-'a'];
            r %= N;
        }
        return r;
    }
};

// 一维滚动优化
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(26, 0));
        // int N = 1E9 + 7;
        const int N = 1000000007;
        for(int i = 0; i < 26; i++){
            dp[0][i] = nums[i];
        }
        for(int i = 1; i < t; i++){
            for(int j = 0; j < 26; j++){
                int n = nums[j];
                dp[i%2][j] = 0;
                for(int k = 1; k <= n; k++){
                    dp[i%2][j] += dp[(i-1)%2][(j+k)%26];
                    dp[i%2][j] %= N;
                }
            }
        }
        int r = 0;
        for(int i = 0; i < s.size(); i++){
            r += dp[(t-1)%2][s[i]-'a'];
            r %= N;
        }
        return r;
    }
};

// 快速幂

int main() {

    return 0;
}