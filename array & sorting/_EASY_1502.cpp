#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i = 1; i < arr.size()-1; i++){
            if(2*arr[i] != arr[i-1]+arr[i+1])return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> arr = {3,5,1};
    cout<<s.canMakeArithmeticProgression(arr)<<endl;
    return 0;
}