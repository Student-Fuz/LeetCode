#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 0; i < intervals.size(); i++){
            int begin = intervals[i][0];
            int end = intervals[i][1];

            if(begin <= result.back()[1]){
                result.back()[1] = max(result.back()[1], end);
            }
            else{
                result.push_back({begin, end});
            }
            
        }

        return result;
    }
};

int main() {

    return 0;
}
