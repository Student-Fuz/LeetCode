#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int val_nums = 0;  
        for(int i=0,j=0; i<nums.size(); i++){
            // 如果不等
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
                val_nums += 1; 
            }
        }
        return val_nums;
    }
};


int main(){ 
    Solution s;
    vector<int> v = {0,1,2,2,3,0,4,2};
    int a = s.removeElement(v,2);
    cout << a << endl;
    return 0;
}