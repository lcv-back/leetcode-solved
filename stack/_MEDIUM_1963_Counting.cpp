#include <iostream>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int stackSize = 0;
		for(auto it : s){
			if(it == '[') stackSize++;
			else if(stackSize > 0) stackSize--;
		}
		return (stackSize + 1) / 2;
    }
};

/*
    Time complexity: O(n)
    Space complexity: O(1)
*/

auto init = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
};

int main(){
	string s = "]]][[[";
	Solution sol;
	cout << sol.minSwaps(s) << endl;
	return 0;
}