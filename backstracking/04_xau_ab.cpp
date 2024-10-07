#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[1005], ok;

void init(){
	for(int i=1;i<=n;i++) a[i]=0;
}

void generate(){
	int i=n;
	while(i>=1&&a[i]==1){
		a[i]=0;
		i--;
	}
	if(i==0) ok=false;
	else{
		a[i]=1;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int t; cin >> t;
	while(t--){
		cin >> n;
		ok=true;
		init();
		while(ok){
			for(int i=1;i<=n;i++){
				if(a[i]==0) cout << "A";
				else cout << "B";
			}
			cout << " ";
			generate();
		}
		cout << endl;
	}
}