#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[1005];

void generate(){
	int i=k;
	while(i>=1&&a[i]==n-k+i) --i;
	if(i==0) for(int i=1;i<=k;i++) a[i]=i;
	else{
		a[i]++;
		for(int j=i+1;j<=k;j++) a[j]=a[j-1]++;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=k;i++) cin >> a[i];
		generate();
		for(int i=1;i<=k;i++) cout << a[i] << " ";
		cout << endl;
	}
}