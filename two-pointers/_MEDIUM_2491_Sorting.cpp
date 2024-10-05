#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static long long dividePlayers(vector<int>& skill) {
        long long totalChemistry = 0;
        int n = skill.size();

        sort(skill.begin(), skill.end());
        int targetTeamSkill = skill[0] + skill[n-1];

        for(int i=0; i<n/2; i++){
            int currentTeamSkill = skill[i] + skill[n-i-1];
            if(currentTeamSkill != targetTeamSkill) return -1;
            totalChemistry += (long long) skill[i] * (long long) skill[n-i-1];
        }

        return totalChemistry;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
	vector<int> skill = {3, 2, 5, 1, 3, 4};
	Solution sol;
	long long res = sol.dividePlayers(skill);
	cout << res << endl;
	return 0;
}