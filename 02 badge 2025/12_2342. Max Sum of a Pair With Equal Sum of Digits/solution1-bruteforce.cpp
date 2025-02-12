#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

/*
input: arr [positive]
process: i and j, i != j, the sum of digits of nums[i] = nums[j]
output: the max value of nums[i] and of nums[j]
*/

class Solution {
public:
    // time: O(n^m) with n is len nums and m is len nums[i], space: O(n)
    int maximumSum(vector<int>& nums) {
    	unordered_map<int,int> map; // sumOfDigit is key and nums[i] is value
    	priority_queue<int> pq;

        for(int n : nums){
        	int sod = sumOfDigit(n);
        	auto it = map.find(sod);
        	if(it != map.end()){
        		pq.push(it->second + n);
        		map[sod] = max(map[sod], n);
        	} else {
        		map[sod] = n;
        	}
        }
        // dont contain valid match
        if(pq.size() == 0) return -1;

        return pq.top();
    }
private:
    // time: O(n), space: O(n)
	int sumOfDigit(int nums){
		int sum = 0;
		while(nums > 0){
			sum += nums % 10;
			nums /= 10;
		}
		return sum;
	}
};

int main(){
	Solution sol;
	vector<int> nums = {17,42,26,15,7};
	int a1 = sol.maximumSum(nums);
	string res = "";
	res = a1 == 57 ? "true" : "false";
	cout << res << endl;

	vector<int> nums1 = {10,12,19,14};
	a1 = sol.maximumSum(nums1);
	cout << "a1: " << a1 << endl;
	res = a1 == -1 ? "true" : "false";
	cout << res << endl;
	return 0;
}

/*
all pairs valid:
- 17 -> 1+7 = 8 <=> 26 -> 2+6 = 8 =>> res: 17+26=43
- 42 -> 4+2 = 6 <=> 15 -> 1+5 = 6 =>> res: 42+15=57
=> res = 57
*/