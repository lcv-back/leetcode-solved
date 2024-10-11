#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// brute force
	/*
    int maxProfit(vector<int>& prices) {
    	if(prices.size() < 2) return 0;
    	
        int result = 0;
        for(int i=0; i < prices.size()-1; i++){
        	int temp = 0;
        	for(int j=i+1; j < prices.size(); j++){
        		temp = max(temp, prices[j] - prices[i]);
			}
			result = max(result, temp);
		}
		
        return result;
    }
    */
    
    // optimize
    int maxProfit(vector<int>& prices){
    	int result = 0, min_price = INT_MAX, max_profit = 0, current_profit = 0;
    	for(int price : prices){
    		if(price < min_price) min_price = price; // find the minimum price
			else {
				current_profit = price - min_price;
				if(max_profit < current_profit) // compare the profit
					max_profit = current_profit;
			}
		}
		
		return max_profit;
	}
};

// time: O(n)
// space: O(1)

int main(){
	vector<int> prices = {7,1,5,3,6,4};
	Solution sol;
	int maxprofit = sol.maxProfit(prices);
	cout << maxprofit;
	return 0;
}
