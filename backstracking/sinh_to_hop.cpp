#include<bits/stdc++.h>
using namespace std;

int x[100], n, ok, k;

void init(){
	for(int i=1; i <= k; i++) x[i]=i;
}

void generate(){
	int i=k;
	while(i >= 1 && x[i]==n-k+i){
		--i;
	}
	if(i==0) ok=false;
	else{
		x[i]++;
		for(int j=i+1; j <= k; j++){
			x[j] = x[j-1]+1;
		}
	}
}

int main(){
	n=4, k=3;
	init();
	ok = true;
	while(ok){
		for(int i = 1; i <= k; i++){
			cout << x[i] << " ";
		}
		cout << endl;
		generate();
	}
	return 0;
}
