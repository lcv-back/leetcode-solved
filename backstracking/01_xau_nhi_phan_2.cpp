#include<bits/stdc++.h>
using namespace std;

int n, a[1000];
bool ok;

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
	else a[i]=1;
}

int main(){
	n=3;
	ok=true;
	init();
	while(ok){
		for(int i=1;i<=n;i++){
			cout << a[i] << " ";
		}
		cout << endl;
		generate();
	}
	return 0;
}
