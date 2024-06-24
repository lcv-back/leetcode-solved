#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void quick_sort(vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int pivot = partition(arr, low, high);

        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }

    int partition(vector<int>& arr, int start, int end) {
        int pivot = arr[start];
        int i = start + 1;
        int j = end;

        while (i <= j) {
            while (i <= j && arr[i] <= pivot) i++;
            while (i <= j && arr[j] > pivot) j--;
            if (i < j) swap(arr[i], arr[j]);
        }

        int pivotIndex = j;
        swap(arr[start], arr[pivotIndex]);

        return pivotIndex;
    }


    int minimumSum(int num) {
        vector<int> arr;
        while(num > 0){
            arr.push_back(num % 10);
            num /= 10;
        }
        quick_sort(arr, 0, arr.size()-1);
        // print(arr);

        int n1 = arr[0] * 10 + arr[3];
        int n2 = arr[1] * 10 + arr[2];

        return n1+n2;
    }
};

int main(){
    Solution s;
    cout << s.minimumSum(1234) << endl;
    return 0;
}