#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i < m && j < n){
        	if(nums1[i] < nums2[j]) i++;
        	else {
        		m++;
        		for(int x = m-1; x > i; x--){
        			nums1[x] = nums1[x-1];
        		}
        		nums1[i] = nums2[j];
        		j++;
        	}
        }

        while(j < n){
        	nums1[i] = nums2[j];
        	i++;
        	j++;
        }
    }
};

int main(){
	Solution sol;
	vector<int> nums1 = {1,2,3,0,0,0};
	vector<int> nums2 = {2,5,6};
	int m = 3;
	int n = 3;
	sol.merge(nums1, m, nums2, n);
	for(int idx : nums1) cout << idx << ' ';
	return 0;
}