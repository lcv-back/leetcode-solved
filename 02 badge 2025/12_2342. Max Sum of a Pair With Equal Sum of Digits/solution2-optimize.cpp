#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	// expect: O(n.logn) with n is len of nums 
    int maximumSum(vector<int>& nums) {
    	int maxSum = -1;
    	vector<pair<int, int>> digit;
        for(int n : nums) digit.push_back({sumOfDigit(n), n});
        sort(digit.begin(), digit.end());
    	for(int i=1; i<digit.size(); i++){
    		int curDigit = digit[i].first;
    		int preDigit = digit[i-1].first;
    		if(curDigit == preDigit){
    			maxSum = max(maxSum, digit[i].second + digit[i-1].second);
    		}
    	}
    	return maxSum;
    }
private:
	int sumOfDigit(int n){
		int sum = 0;
		while(n > 0){
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
};

int main(){
	Solution sol;
	vector<int> nums = {18,43,36,13,7};
	cout << sol.maximumSum(nums) << endl;
	return 0;
}