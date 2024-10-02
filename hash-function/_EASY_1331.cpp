#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res;

        // storage the rank for elements
        unordered_map<int, int> mp;
        int startRank = 1;

        // copied array to can modify the original array
        vector<int> temp = arr;

        // sorting the copied array
        sort(temp.begin(), temp.end());

        // set rank
        for(auto num : temp){
            if(mp.find(num) == mp.end()){
                mp[num] = startRank;
                startRank++;
            }
        }

        for(auto num : arr){
            res.push_back(mp[num]);
        }


        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {40,10,20,30};
    vector<int> res = s.arrayRankTransform(arr);
    for(auto i : res) cout<<i<<" ";
    return 0;
}