#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;

void init(){
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
}

void generate(){
	// bat dau tu vi tri n - 1
	// chung nao a[i] > a[i+1] thi phai dich sang ben phai
	int i = n-1;
	while(i >= 1 && a[i] > a[i+1]){
		--i;
	}
	
	if(i == 0) ok = false;
	else {
		// da tim ra a[i] < a[i+1]
		// di tim so dung sau vi tri i va > a[i], va nho nhat co the
		int j = n; // bat dau tu chi so cuoi cung, bo qua cac vi tri ma a[j] < a[i]
		while(a[i] > a[j]) --j;
		// a[j]: phan tu lon hon a[i] ma nho nhat
		swap(a[i], a[j]);
		//sap xep cac phan tu tu i+1 => n theo thu tu tang dan
		// c1: sort(a+i+1, a+n+1); // O(nlogn)
		// c2: lat nguoc toan tu i+1 =>
		reverse(a+i+1, a+n+1); // O(n)
	
	}
}

int main(){
	cin >> n;
	init();
	ok = true;
	while(ok){
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		generate();
	}
}
