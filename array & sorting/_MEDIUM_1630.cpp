#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void quick_sort(vector<int>& arr, int low, int high){
		// base case
		if(low >= high) return;

		// partition
		int pivot = partition(arr, low, high);

		// repeat for the left side
		quick_sort(arr, low, pivot-1);

		// repeat for the right side
		quick_sort(arr, pivot+1, high);
	}

	int partition(vector<int>& arr, int start, int end){
		int key = arr[start];
		int i = start;
		int j = end;
		while(i <= j){
			while(i <= j && arr[i] <= key) i++;
			while(i <= j && arr[j] > key) j--;
			if(i < j){
				swap(arr[i], arr[j]);
			}
		}
		int pivotIndex = j;
		swap(arr[start], arr[pivotIndex]);

		return pivotIndex;
	}

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        vector<int> temp;
        for(int i = 0; i < l.size(); i++){
        	for(int j = l[i]; j <= r[i]; j++){
        		temp.push_back(nums[j]);
        	}
        	quick_sort(temp, 0, temp.size()-1);

        	int flag = 0;

        	if(temp.size() < 2) res.push_back(true);

        	for(int i = 2; i < temp.size(); i++){
        		int base = temp[1] - temp[0];
        		if((temp[i] - temp[i-1]) != base){
        			res.push_back(false);
        			flag = 1;
        			break;
        		}
        	}
        	if(flag == 0) res.push_back(true);
        	else flag = 0;

        	temp.clear();
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,6,5,9,3,7};
    vector<int> l = {0,0,2};
    vector<int> r = {2,3,5};
    vector<bool> res = s.checkArithmeticSubarrays(nums, l, r);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}