#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squareNums; 
        squareNums.reserve(nums.size());  // 预留空间，提升性能
        for(int num : nums){
            squareNums.push_back(num * num);
        }
        std::sort(squareNums.begin(),squareNums.end());
        return squareNums;
    }
};


int main(){ 
    Solution s;
    vector v = {0,1,2,2,3,0,4,2};
    vector s_v = s.sortedSquares(v);
    for(int num : s_v)
        cout << num;
    cout << endl;
    return 0;
}