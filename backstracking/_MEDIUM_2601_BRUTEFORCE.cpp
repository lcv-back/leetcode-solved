#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPrime(int num){
		for(int i=2; i<=sqrt(num); i++) 
			if(num % i == 0)
				return 0;
		return 1;
	}

	bool primeSubOperation(vector<int>& nums){
		if(nums.size() <= 1) return true;

		for(int i=0; i<nums.size(); i++){
			int bound = 0;
			i == 0 ? bound = nums[0] : bound = nums[i] - nums[i-1];
			if(bound<=0) return false;

			// find the largest prime
			int largestPrime = 0;
			for(int j = bound -1; j >= 2; j--){
				if(isPrime(j)){
					largestPrime = j;
					break;
				}
			}
			nums[i] -= largestPrime;
		}
		return true;
	}
};

auto init = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
};

int main(){
	Solution sol;
	vector<int> nums = {4,9,6,10};
	cout << sol.primeSubOperation(nums) << endl;
	return 0;
}