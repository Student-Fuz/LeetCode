#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针法
        int slow = 0, fast = 0;
        for(; fast < nums.size(); fast++){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};


int main(){ 
    Solution s;
    vector<int> v = {0,1,2,2,3,0,4,2};
    int a = s.removeElement(v,2);
    cout << a << endl;
    return 0;
}