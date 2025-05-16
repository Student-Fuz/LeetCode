#include <bits/stdc++.h>
using namespace std;

// 链接： https://leetcode.cn/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> showed;

        while(showed.count(n) == 0){
            showed.insert(n);

            int next_n = 0;
            while(n != 0){
                int tmp = (n%10);
                next_n += tmp * tmp;
                n /= 10;
            }

            n = next_n;
        }

        return showed.count(1);
    }
};

int main() {

    return 0;
}