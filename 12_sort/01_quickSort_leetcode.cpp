#include <bits/stdc++.h>
using namespace std;

// 题目链接：
// https://leetcode.cn/problems/sort-an-array/

// 分区函数，返回基准元素的位置
class solution{
private:
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; 
        int i = low - 1; // i 是小于等于 pivot 的元素的区域的边界

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++; 
                std::swap(arr[i], arr[j]); 
            }
        }
        // 将基准元素放到正确的位置
        std::swap(arr[i + 1], arr[high]);
        return i + 1; // 返回基准元素的位置
    }

public:
    // 快速排序函数
    // 区间左闭右闭
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // 找到基准元素的位置
            int pi = partition(arr, low, high);

            // 对基准元素左边的部分排序
            quickSort(arr, low, pi - 1);
            // 对基准元素右边的部分排序
            quickSort(arr, pi + 1, high);
        }
    }
};

class Solution {
private:
    // 左闭右闭
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[high];
        // 小于等于pivot的边界
        int i = low - 1; 

        for(int j = low; j < high; j++){
            if(nums[j] < nums[high]){
                i++;
                swap(nums[i], nums[j]);
            }
        }

        i++;
        swap(nums[i], nums[high]);
        return i;

    }

    void quickSort(vector<int>& nums, int low, int high){
        if(low < high){
            int pi = partition(nums, low, high);
            quickSort(nums, pi+1, high);
            quickSort(nums, low, pi-1);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);

        // m1
        // vector<int> result(nums.begin(), nums.end());
        // return result;

        // m2
        return nums;
    }
};

int main() {

    return 0;
}