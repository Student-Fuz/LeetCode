#include <iostream>
#include <vector>

using namespace std;

// 分区函数，返回基准元素的位置
class solution{
private:
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // 选择最右边的元素作为基准
        int i = low - 1; // i 是小于等于 pivot 的元素的区域的边界

        for (int j = low; j < high; j++) {
            // 如果当前元素小于或等于基准
            if (arr[j] <= pivot) {
                i++; // 增加小于等于基准区域的边界
                std::swap(arr[i], arr[j]); // 将当前元素与小于等于基准区域的第一个元素交换
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

// 分区函数，返回基准元素的位置
class solution{
public:
    // 快速排序函数
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // 获取分区点
            int pivot = arr[high];
            int i = low - 1;

            // 进行分区操作
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }

            // 将基准元素交换到正确的位置
            swap(arr[i + 1], arr[high]);

            // 对基准元素左右两侧递归进行排序
            quickSort(arr, low, i);
            quickSort(arr, i + 2, high);
        }
    }
};


int main() {

}
