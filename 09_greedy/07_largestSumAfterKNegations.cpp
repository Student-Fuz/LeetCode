#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/

/*
第一次做题时想法 
思路：
1. 如果翻转次数k<=负数值个数，则找绝对值最大的负数进行翻转

2. 如果翻转次数k>负数值个数
  2.1 多2n个次数，不影响结果
  2.2 多2n+1个次数，翻转绝对值最小的正数、负数

*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        vector<int> vec_p;
        vector<int> vec_n;

        for(auto& num: nums){
            if(num > 0) vec_p.push_back(num);
            else vec_n.push_back(num);
        }

        // sort(vec_p.begin(), vec_p.end());
        // sort(vec_n.begin(), vec_n.end());

        int result = 0;

        if(k <= vec_n.size()){
            sort(vec_n.begin(), vec_n.end());
            for(const auto& num : vec_p) result += num;
            for(int i = 0; i < k; i++){
                result -= vec_n[i];
            }
            for(int i = k; i < vec_n.size(); i++){
                result += vec_n[i];
            }
        }
        else{
            if((k-vec_n.size()) % 2 != 1){
                for(const auto& num : vec_p) result += num;
                for(const auto& num : vec_n) result -= num;
            }
            else{
                sort(vec_p.begin(), vec_p.end());
                sort(vec_n.begin(), vec_n.end());
                for(const auto& num : vec_p) result += num;
                for(const auto& num : vec_n) result -= num;
                if((!vec_n.empty() && !vec_p.empty())){
                    if(-vec_n.back() > vec_p.front()){
                        result -= 2 * vec_p.front();
                    }
                    else{
                        result += 2 * vec_n.back();
                    }
                } 
                else{
                    if(vec_n.empty()){
                        result -= 2 * vec_p.front();
                    }
                    else{
                        result += 2 * vec_n.back();
                    }
                }
                
            }
        }
        return result;
    }
};

/* 
贪心算法
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
    }
};


int main() {

    return 0;
}
