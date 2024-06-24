#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n==0||n==1||n==2) return 0;
		bool pr[n+1];
		for(int i=0; i<=n;i++) pr[i]=true;
		pr[0]=pr[1]=false;
		for(int i=2; i<=sqrt(n);i++) if(pr[i]) for(int j=i*i;j<=n;j+=i) pr[j]=false;
		int ans = 0;
		for(int i =0; i<n; i++) if(pr[i]) ans++;
		return ans;
    }
};

int main(){
    Solution s;
    cout<<s.countPrimes(10)<<endl;
    return 0;
}