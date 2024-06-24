#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = names.size();
        pair<int, string> p[n];
        for(int i = 0; i < n; i++){
            p[i].first = heights[i];
            p[i].second = names[i];
        }
        sort(p, p + n, [](const pair<int, string>& a, const pair<int, string>& b) -> bool {
            return a.first > b.first;
        });
        vector<string> ans;
        for(int i = 0; i < n; i++)
            ans.push_back(p[i].second);
        return ans;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> heights(n);
    for(int i = 0; i < n; i++)
        cin >> names[i];
    for(int i = 0; i < n; i++)
        cin >> heights[i];
    vector<string> ans = s.sortPeople(names, heights);
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}