#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

    int n=items.size();
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (ruleKey == "type")
        {
            if (ruleValue == items[i][0])
            {
                count++;
            }
        }
        else if (ruleKey == "color")
        {
            if (ruleValue == items[i][1])
            {
                count++;
            }
        }
        else if (ruleKey == "name")
        {
            if (ruleValue == items[i][2])
            {
                count++;
            }
        }
    }
    return count;


    }
};

int main(){
    Solution s;
    vector<vector<string>> items = {{"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}};
    string ruleKey = "color";
    string ruleValue = "silver";
    cout<<s.countMatches(items,ruleKey,ruleValue)<<endl;
    return 0;
}