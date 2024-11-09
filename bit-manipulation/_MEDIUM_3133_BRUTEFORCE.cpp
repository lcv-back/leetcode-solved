#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    long long minEnd(int n, int x) {
        vector<long long> nums(n, 0);
        long long lastValue = x;
        nums[0] = lastValue;
        long long currentValue = lastValue + 1;
        
        for(int i=1; i<n; i++){
        	while((nums[0] & currentValue) != lastValue){
        		currentValue++;
        	}

        	nums[i] = currentValue;
        	currentValue++;
        }

        return nums[n-1];
    }
};

int main(){
	Solution sol;
	int n=3, x=4;
	long long minimum = sol.minEnd(n, x);
	cout << minimum << endl;
}