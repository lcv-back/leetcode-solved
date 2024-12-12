#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res = 0;
        priority_queue<int> pq;
        for(int x : gifts) pq.push(x);
        while(k-- > 0){
        	int curTop = pq.top();
        	pq.pop();
        	pq.push((int)sqrt(curTop));
        }

        while(!pq.empty()){
        	res += pq.top();
        	pq.pop();
        }
        return res;
    }
};

int main(){
	Solution sol;
	vector<int> gifts = {25,64,9,4,100};
	int k = 4;
	long long res = sol.pickGifts(gifts, k); //output: 29
	cout << res << endl;
	return 0;
}