#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
	TreeNode* buildTree(string& s, int& i, int depth) {
		// Check if current depth matches the required depth by counting dashes
		int current_depth = 0;
		while (i < s.length() && s[i] == '-') {
			current_depth++;
			i++;
		}
		
		// If depth doesn't match, return null
		if (current_depth != depth) {
			i -= current_depth; // backtrack
			return nullptr;
		}
		
		// Parse number
		int val = 0;
		while (i < s.length() && isdigit(s[i])) {
			val = val * 10 + (s[i] - '0');
			i++;
		}
		
		// Create new node
		TreeNode* root = new TreeNode(val);
		
		// Try to build left and right subtrees
		root->left = buildTree(s, i, depth + 1);
		root->right = buildTree(s, i, depth + 1);
		
		return root;
	}

public:
	TreeNode* recoverFromPreorder(string s) {
		int i = 0;
		return buildTree(s, i, 0);
	}
};

void print(TreeNode* root){
	if(!root) return;
	cout << root->val << " ";
	print(root->left);
	print(root->right);
}

int main() {
	Solution s;
	string traversal = "1-2--3--4-5--6--7";
	TreeNode* res = s.recoverFromPreorder(traversal);
	print(res);
	return 0;
}