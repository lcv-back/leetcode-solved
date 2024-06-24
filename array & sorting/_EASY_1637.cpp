#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        int n = points.size();
        
        //sort the array on the first value in ascending order.
        sort(points.begin(), points.end());

        //Calculating Area between each points and maintining that in maxArea
        int maxArea = 0;
        for(int i=1;i<n;i++) {
            int currArea = points[i][0]-points[i-1][0];
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
        
    }
};

int main(){
    Solution s;
    vector<vector<int>> points = {{8,7},{9,9},{7,4},{9,7}};
    cout<<s.maxWidthOfVerticalArea(points)<<endl;
    return 0;
}