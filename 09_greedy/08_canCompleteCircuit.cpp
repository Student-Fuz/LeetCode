#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/gas-station/

// m1
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minGas = INT_MAX; // 油箱剩的最少油
        int curSum = 0; // 当前油箱中的油

        for(int i = 0; i < gas.size(); i++){
            int res = gas[i] - cost[i];
            curSum += res;
            minGas = min(minGas, curSum);
        }

        if(curSum < 0) return -1;
        if(minGas >= 0) return 0;

        // 从i开始跑到0，保证从0开始油量大于等于minGas，使得之后从0开始后的剩余油量都大于等于0
        for(int i = gas.size()-1; i >= 0 ; i--){
            int res = gas[i] - cost[i];
            minGas += res;
            if(minGas >= 0) return i;
        }

        return -1;
    }
};

// m2
// 局部最优---->全局最优
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start;
    }
};

int main() {

    return 0;
}