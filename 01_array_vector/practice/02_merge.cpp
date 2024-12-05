#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> nums;
        int index = 0 , index_1 = 0, index_2 = 0;
        while(nums.size() < m+n){
            if(index_1 < m && index_2 < n){
                if(nums1[index_1] < nums2[index_2])
                    nums.push_back(nums1[index_1++]);
                else
                    nums.push_back(nums2[index_2++]);  
            }
            else{
                if(index_1 == m)
                    nums.push_back(nums2[index_2++]); 
                else
                    nums.push_back(nums1[index_1++]);
            }
        }
        nums1.assign(nums.begin(), nums.end());
    }
};

int main(){

    Solution s;

    return 0;
}