#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
    	sort(folder.begin(), folder.end());
    	vector<string> result;
    	result.push_back(folder[0]);
    	
    	for(int i=1; i<folder.size(); i++){
    		string lastFolder = result.back();
    		lastFolder += '/';
    		if(folder[i].compare(0, lastFolder.size(), lastFolder) != 0){
    			result.push_back(folder[i]);
			}
		}
		
		return result;
    }
};

int main(){
	Solution sol;

	vector<string> folder1 = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
	vector<string> removeFolder = sol.removeSubfolders(folder1);
	for(auto folder : removeFolder){
		cout << folder << " " << endl;
	}
	return 0;
}
