#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/queue-reconstruction-by-height/description/

class Solution {
private:
    static bool cmp(vector<int>& left, vector<int>& right){
        // 0相同，按1升序排列
        if(left[0] == right[0])
            return left[1] < right[1];
        return left[0] > right[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> result;
        result.reserve(people.size());

        for(auto person : people){
            result.insert(result.begin()+person[1], person);
        }

        return result;
    }
};

int main() {

    return 0;
}
