#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0,j=0,s=0;
        while(i<mat.size()){
            s+=mat[i][j];
            i++;
            j++;
        }
        j=mat.size()-1,i=0;
        while(i<mat.size()){
            if(i!=j)
               s+=mat[i][j];
            i++;
            j--;   
        }
        return s;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    cout<<s.diagonalSum(v)<<endl;
    return 0;
}