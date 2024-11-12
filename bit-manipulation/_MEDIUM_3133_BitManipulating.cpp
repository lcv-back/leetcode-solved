#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    long long minEnd(int n, int x) {
        vector<short> shifts;
        long long cur = x;
        long long calc = n - 1;
        
        for(int i = 0; i < 32; i++) //find bit positions in x which are 0
            if(!((1 << i) & x))
                shifts.push_back(i);
        for(int i = 32; i < 64; i++)
            shifts.push_back(i);
        
        for(int i = 0; calc > 0; i++, calc >>= 1) {
            cur += (calc & 1) << shifts[i];
        }
        return cur;
    }
};
int main(){
	Solution sol;
	int n=3, x=4;
	long long minimum = sol.minEnd(n, x);
	cout << minimum << endl;
}