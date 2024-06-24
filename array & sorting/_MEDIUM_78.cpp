#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, x[100], ok;

    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> res;
    	n = nums.size();
    	ok=true;
    	init();

    	while(ok){
    		vector<int> temp;
    		for(int i=0; i<n; i++){ // changed size range from 'i=1 to i<=n' to 'i=0 to i < n'
    			if(x[i]==1){
					temp.push_back(nums[i]);
    			} 
    			// don't need to clear the temp
    		}
    		res.push_back(temp);
    		generate();
    	}

    	return res;
    }

    void init(){
    	for(int i=0; i<n; i++) x[i]=0; // changed from 'i=1' to 'i=2'
    }

	void generate(){
		int i=n-1; // 'i=n to i=n-1'
		while(i>=0 && x[i]==1){ // changed from 'i>=1' to 'i>=0'
			x[i]=0;
			i--;
		}

		if(i<0) ok=false; // changed from 'i==0' to 'i<0'
		else x[i]=1;
	}
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.subsets(nums);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}