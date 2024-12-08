#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Tìm đoạn không giảm từ trái sang phải
        while (left < n - 1 && arr[left] <= arr[left + 1]) left++;

        // Nếu toàn bộ mảng đã không giảm
        if (left == n - 1) return 0;

        // Tìm đoạn không giảm từ phải sang trái
        while (right > 0 && arr[right - 1] <= arr[right]) right--;

        // Xóa toàn bộ từ trái hoặc toàn bộ từ phải
        int result = min(n - left - 1, right);

        // Thử nối hai đoạn
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};

int main(){
	Solution sol;
	vector<int> arr = {1,2,3,10,4,2,3,5};
	cout << sol.findLengthOfShortestSubarray(arr) << endl;
	return 0;
}