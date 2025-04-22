#include<iostream>
#include<vector>

using namespace std;

// 升序序列，二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid = (left + right)/2;

        while(left <= right){
            mid = (left + right)/2; 
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            } 
        }
        
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