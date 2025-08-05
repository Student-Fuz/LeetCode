#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/fruit-into-baskets/description/?envType=daily-question&envId=2025-08-04

// 滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int maxSum = 0;
        // int fruit1, fruit2;
        unordered_set<int> bucket;
        int sum = 0;

        for(int i = 0; i < fruits.size(); i++){
            if(bucket.size() < 2){
                bucket.insert(fruits[i]);
                sum++;
                maxSum = max(maxSum, sum);
            }
            else{
                if(bucket.count(fruits[i])){
                    sum++;
                    maxSum = max(maxSum, sum);
                }
                else{
                    maxSum = max(maxSum, sum);
                    sum = 0;
                    bucket = {fruits[i], fruits[i-1]};
                    for(int j = i; j >= 0; j--){
                        if(bucket.count(fruits[j]) == 0) break;
                        sum++;
                        maxSum = max(maxSum, sum);
                    }
                }
            }
        }

        return maxSum;
    }
};

// 理解错题意--采摘连续
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // 左闭右开
        int start1 = 0, start2 = 0, end1 = 0, end2 = 0;

        int maxSum = 0;

        for(; end2 < fruits.size(); end2++){
            if(fruits[end2] != fruits[start2]){
                int sum = end1 - start1 + end2 - start2;
                maxSum = max(maxSum, sum);
                start1 = start2;
                end1 = end2;
                start2 = end2;
            }
        }

        int sum = end1 - start1 + end2 - start2;
        maxSum = max(maxSum, sum);

        return maxSum;
    }
};

int main() {

    return 0;
}