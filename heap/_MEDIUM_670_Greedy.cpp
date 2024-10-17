#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.length();
        vector<int> maxRightIndex(n);

        maxRightIndex[n-1] = n-1;

        for(int i=n-2; i>=0; i--){
            if(numStr[i] > numStr[maxRightIndex[i+1]]) maxRightIndex[i] = i;
            else maxRightIndex[i] = maxRightIndex[i+1];
        }

        for(int i=0; i<n;i++){
            if(numStr[i] < numStr[maxRightIndex[i]]) {
                swap(numStr[i], numStr[maxRightIndex[i]]);
                return stoi(numStr);
            }
        }
        return num;
    }
};

int main(){
    int num = 2736;
    Solution sol;
    cout << sol.maximumSwap(num) << endl;
    return 0;
}