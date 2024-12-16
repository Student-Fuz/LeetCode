#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述


// Solution
// 时间复杂度O(N^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_on_car = 0;

        for(int i = 0; i < cost.size(); i++){
            gas_on_car = gas_on_car + gas[i] - cost[i];
        }
        if(gas_on_car <  0)
            return -1;
        
        for(int i = 0; i < cost.size(); i++){
            gas_on_car = 0;
            for(int j = 0; j < cost.size(); j++){
                int cur = (i + j)%cost.size();
                // 当前无法启动
                if(gas[cur] == 0 && gas_on_car == 0){
                    gas_on_car = -1;
                    break;
                }
                gas_on_car = gas_on_car + gas[cur] - cost[cur];
                // 无法到达下一地点
                if(gas_on_car < 0)
                    break;
            }
            if(gas_on_car >= 0)
                return i;
        }
        return -1;
    }
};

// 优化--贪心算法
// 有结论如下：
// 从 x,y 之间的任何一个加油站出发，都无法到达加油站 y 的下一个加油站。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_on_car = 0;
        
        for(int i = 0; i < cost.size(); i++){
            gas_on_car = gas_on_car + gas[i] -cost[i];
        }

        return -1;
    }
};

int main(){

    Solution s;

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    s.canCompleteCircuit(gas, cost);

    return 0;
}