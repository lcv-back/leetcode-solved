#include<bits/stdc++.h>
using namespace std;

int a[100], n, k, ok;

void init(){
	for(int i=1;i<=n;i++) a[i] = i;
}

void generate(){
	int i=n-1;
	while(i>=1&&a[i]==n-k+i){
		i--;
	}
	if(i==0) ok=false;
	else{
		a[i]++;
		for(int j=i+1; j<=k; j++) a[j]=a[j-1]++;
	}
}

int main(){
	n=5, k=3;
	ok=true;
	init();
	while(ok){
		for(int i=1;i<=k;i++) cout << a[i] << " ";
		cout << endl;
		generate();
	}
	return 0;
}