#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[10005];

void generate(){
	int i=n-1;
	while(i>=1&&a[i]>a[i+1]){
		--i;	
	}

	if(i==0) for(int i=1;i<=n;i++) a[i]=i;
	else{
		int j=n;
		while(a[i]>a[j]) j--;
		swap(a[i], a[j]);
		reverse(a+i+1, a+n+1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		generate();
		for(int i=1;i<=n;i++) cout << a[i] << " ";
		cout << endl;
	}
}