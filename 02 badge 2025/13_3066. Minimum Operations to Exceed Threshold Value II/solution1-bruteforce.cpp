#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MinHeapComparator {
public:
	bool operator()(int a, int b){
		return a > b;
	}
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int min_opes = 0;
        priority_queue<long, vector<long>, greater<long>> pq;

        for(int x : nums) pq.push(x);
    
    	while(pq.top() < k){
    		min_opes++;
    		long x = pq.top();
    		pq.pop();
    		long y = pq.top();
    		pq.pop();
    		long add_value = addValue(x, y);
    		nums.push_back(add_value);
    		pq.push(add_value);
    	}

        return min_opes;
    }
private:
	long addValue(long x, long y){
		return min(x, y) * 2 + max(x, y);
	}
};

int main(){
	Solution sol;
	vector<int> nums = {2,11,10,1,3};
	int k = 10;
	cout << sol.minOperations(nums, k) << endl;
	return 0;
}