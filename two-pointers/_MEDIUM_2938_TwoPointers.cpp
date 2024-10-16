#include <string>
#include <iostream>
using namespace std;

/*
	The approach: Two pointers
	Key approach: The number of swaps = the gap between current position and final position
	(For white ball)

*/
class Solution {
public:
    long long minimumSteps(std::string s) {
        int whitePosition = 0;
        long long totalSwaps = 0;

        for(int i=0; i<s.size(); i++){
        	if(s[i]=='0'){
        		totalSwaps += i - whitePosition;
        		whitePosition++;
        	}
        }

        return totalSwaps;
    }
};

/*
	Time complexity: O(n) and Space complexity: O(1)
	with n is the length of string s
*/

int main(){
	string s1 = "101";
	Solution sol;
	cout << sol.minimumSteps(s1) << endl;

	string s2 = "100";
	cout << sol.minimumSteps(s2) << endl;
	return 0;
}