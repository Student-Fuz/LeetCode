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

        list<vector<int>> result_list;

        for(auto person : people){
            int pos = person[1];
            auto it = result_list.begin();
            for(int i = 0; i < pos; i++){
                it++;
            }
            result_list.insert(it, person);
        }

        vector<vector<int>> result;
        for(auto it = result_list.begin(); it != result_list.end(); it++){
            result.push_back(*it);
        }

        return result;
    }
};

int main() {

    return 0;
}
