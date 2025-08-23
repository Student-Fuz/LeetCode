#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/median-of-two-sorted-arrays/?envType=study-plan-v2&envId=top-100-liked

// 暴力
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size() + nums2.size())/2;
        int i = 0, j = 0;
        int prev = 0, curr = 0;

        while(i + j != mid+1){
            prev = curr;
            if(i != nums1.size() &&(j == nums2.size() || nums1[i] < nums2[j]) ){
                curr = nums1[i++];
            }
            else{
                curr = nums2[j++];
            }
        }

        if((nums1.size() + nums2.size())%2){
            return curr;
        }
        else{
            return (prev+curr)/2.0;
        }

    }
};

int main() {

    return 0;
}