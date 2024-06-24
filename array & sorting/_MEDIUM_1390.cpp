#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int division(int n){
		int divSum = 0, sum = 0;
		for(int i = 1; i <= sqrt(n); i++){
			if(n % i == 0){
				if(n/i != i){
					sum += i + n/i;
					divSum+=2;
				} else{
					sum += i;
					divSum++;
				}
				if(divSum > 4) return 0;
			}
		}
		if(divSum == 4) return sum;
		return 0;
	}

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
        	ans += division(nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {21,4,7};
    cout << s.sumFourDivisors(nums) << endl;
    return 0;
}