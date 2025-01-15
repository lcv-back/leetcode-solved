#include<iostream>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
    	int countOnes = __builtin_popcount(num2); // Đếm số bit 1 trong num2
	    int x = 0;
	    for (int i = 31; i >= 0 && countOnes > 0; i--) {
	        if (num1 & (1 << i)) {
	            x |= (1 << i);
	            countOnes--;
	        }
	    }
	    for (int i = 0; i <= 31 && countOnes > 0; i++) {
	        if (!(x & (1 << i))) {
	            x |= (1 << i);
	            countOnes--;
	        }
	    }
	    return x;	
    }

};

int main(){
	Solution sol;
	int num1 = 3;
	int num2 = 5;
	cout << sol.minimizeXor(num1, num2) << endl;
	return 0;
}