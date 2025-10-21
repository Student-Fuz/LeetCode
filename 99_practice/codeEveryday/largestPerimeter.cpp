#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = (int)nums.size() - 1; i >= 2; --i) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
};

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int maxArea = 0;
        if(nums.size() < 3) return maxArea;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int k = i + 2;
            for(int j = i+1; j < nums.size()-1; j++){
                while(k < nums.size() && nums[k] < nums[i] + nums[j]){
                    k++;
                }
                if(k != j+1) maxArea = max(maxArea, nums[i]+nums[j]+nums[k-1]);
            }
        } 
        return maxArea;
    }
};

int main() {

    return 0;
}