#include <bits/stdc++.h>
using namespace std;

int n, a[1005];
bool ok;

void init() {
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}

void generate() {
    int i=n-1;
    while(i>=1&&a[i]>a[i+1]){
        i--;
    }
    if(i==0) ok=false;
    else{
        int j=n;
        while(a[i]>a[j]) j--;
        swap(a[i], a[j]);
        reverse(a+i+1, a+n+1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        ok = true;
        while (ok) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            generate();
        }
        cout << endl;
    }

    return 0;
}
