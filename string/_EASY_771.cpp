#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
    	int count = 0;
    
    	for (char stone : stones) {
	        if (jewelSet.find(stone) != jewelSet.end()) {
	            count++;
	        }
    	}
    
    	return count;
    }
};

int main(){
    Solution s;
    cout << s.numJewelsInStones("aA", "aAAbbbb");
    return 0;
}