#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int s_n = newInterval[0], e_n = newInterval[1];
        int i = 0;
        for(; i < intervals.size(); i++){
            int s = intervals[i][0], e = intervals[i][1];
            if(e < s_n){
                result.push_back(intervals[i]);
                continue;
            }
            if((s <= s_n && s_n <= e) || ( s <= e_n && e_n <= e) || (s_n <= s && e_n >= e)) {
                s_n = min(s, s_n);
                e_n = max(e_n, e);
                continue;
            }
            break;
        }
        result.push_back({s_n, e_n});
        for(; i < intervals.size(); i++){
            result.push_back(intervals[i]);
        }
        return result;
    }
};

int main() {

    return 0;
}