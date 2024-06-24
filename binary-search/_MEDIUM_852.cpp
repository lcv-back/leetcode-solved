#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size()-1;
        int mid=(start+end)/2;
        while(start<end){
            if(arr[mid]<arr[mid+1]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=(start+end)/2;
        }
        return start;
    }
};

int main(){
    Solution s;
    vector<int> arr={0,2,1,0};
    cout<<s.peakIndexInMountainArray(arr)<<endl;
    return 0;
}