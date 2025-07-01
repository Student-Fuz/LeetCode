#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/non-overlapping-intervals/


/* 
思想：
  非交叉区间尽可能地多：所以找右端点尽可能地小
*/
class Solution {
public:
    // 按照区间右边界排序
    static bool cmp (const vector<int>& l, const vector<int>& r) {
        return l[1] < r[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1; // 记录非交叉区间的个数
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};

int main() {

    return 0;
}
