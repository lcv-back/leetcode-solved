#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
    input:
    given an array of positive integer 
    a integer 

    process:
    remove the smallest subarray (possibly empty)
    such the sum of the remaining elements is divisible by p
    not allowed to remove the whole array

    output:
    return the length of the smallest subarray
    if it's impossible return -1

    analysis requirement:
    the sum of the remaining elements equal to the sum of subarray need to remove
    => how to calculate the sum need to remove?
    s(remove) = s(all) - s(remaining)
    => s(remove) = s(all) modulo p

    result 1: if output is the length of subarray need to remove
    

*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    	long totalSum = 0;
    	for(int num : nums) totalSum += num;

    	int remainder = totalSum % p; // the expected sum need to remove subarray
    	if(remainder == 0) return 0;

    	unordered_map<int, int> prefixMap;
    	prefixMap[0] = -1;
    	long prefixSum = 0;
    	int minLength = nums.size();

    	for(int i=0; i<nums.size(); i++){
    		prefixSum += nums[i];
    		int curMod = prefixSum % p;
    		int targetMod = (curMod - remainder + p) % p;

    		if(prefixMap.find(targetMod) != prefixMap.end()){
    			minLength = min(minLength, i - prefixMap[targetMod]);
    		}

    		prefixMap[curMod] = i;
    	}

    	return minLength == nums.size() ? -1 : minLength;
    }
};

int main(){
	vector<int> nums = {6,3,5,2};
	int p = 9;
	Solution sol;
	int res = sol.minSubarray(nums, p);
	cout << res << endl;
	return 0;
}