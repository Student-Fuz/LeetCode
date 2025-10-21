#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/count-symmetric-integers/?envType=daily-question&envId=2025-09-05

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int n = low; n <= high; n++){
            int len = 0;
            int num = n;
            vector<int> poses;
            while(num != 0){
                int pos = num % 10;
                num /= 10;
                poses.push_back(pos);
            }
            if(poses.size()%2) continue;
            int l = 0, r = 0;
            for(int i = 0, j = poses.size()/2; i < poses.size()/2; i++, j++){
                l += poses[i];
                r += poses[j];
            }
            if(l == r) cnt++;
        }
        return cnt;
    }
};

int main() {

    return 0;
}