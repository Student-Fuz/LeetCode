#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/lemonade-change/

// 所以局部最优：遇到账单20，优先消耗美元10，完成本次找零。全局最优：完成全部账单的找零。

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num_5 = 0;
        int num_10 = 0;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                num_5++;
            }else if(bills[i] == 10){
                num_10++;
                if(--num_5 < 0) return false;
            }else{
                if(num_10){
                    num_10--;
                    if(--num_5 < 0) return false;
                }else{
                    num_5 -= 3;
                    if(num_5 < 0) return false;
                }
            }
        }

        return true;
    }
};

int main() {

    return 0;
}
