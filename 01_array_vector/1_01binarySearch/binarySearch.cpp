#include<iostream>
#include<vector>

using namespace std;

// 升序序列，二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        
        while(right >= left){
            // 注意C语言的除法向零取整（舍弃小数部分）。
            mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            // 在前半区间查找
            else if(nums[mid] > target){
                right = mid - 1;
            }
            // 在后半区间查找
            // mid < target
            else{
                left = mid + 1;
            }
        }
        // target not found
        return -1;
    }
};


int main(){ 
    Solution s;
    vector<int> v = {-1,0,3,5,9,12};
    int a = s.search(v,9);
    cout << a << endl;
    return 0;
}