#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n + 1, 0);

        // Process the shifts
        for (auto& shiftOp : shifts) {
            int start = shiftOp[0], end = shiftOp[1], direction = shiftOp[2];
            shift[start] += (direction == 1 ? 1 : -1);
            shift[end + 1] -= (direction == 1 ? 1 : -1);
        }

        int currentShift = 0;
        for (int i = 0; i < n; ++i) {
            currentShift += shift[i];
            shift[i] = currentShift;
        }

        for (int i = 0; i < n; ++i) {
            int netShift = (shift[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    vector<vector<int>> shifts = {{0,1,0}, {1,2,1}, {0,2,1}};

    string s1 = "dztz";
    vector<vector<int>> shifts1 = {{0,0,0}, {1,1,1}};
    cout << sol.shiftingLetters(s1, shifts1) << endl;
    return 0;
}
