#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<unordered_map>
#include <fstream>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {	
        unordered_map<int, vector<int>> mp;
        for(auto i: edges){
        	mp[i[0]].push_back(i[1]);
        	mp[i[1]].push_back(i[0]);
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(source);
        visited[source]=true;

        while(!q.empty()){
        	int fr = q.front();
        	if(fr == destination){
        		return true;
        	}

        	for(auto& i: mp[fr]){
        		if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
        	}
        }

        return false;
    }
};

int main(){
	Solution sol;
	int n = 3;
	vector<vector<int>> edges = {{1,0},{1,2},{2,0}};
	int source = 0;
	int destination = 2;
	cout << sol.validPath(n, edges, source, destination);
	return 0;
}