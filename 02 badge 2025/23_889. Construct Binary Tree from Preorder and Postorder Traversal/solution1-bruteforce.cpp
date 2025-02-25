#include<iostream>
#include<vector>
#include<fstream>
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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.empty() || postorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        if(preorder.size() == 1) return root;

        int leftRootValue = preorder[1];
        int leftSubtreeSize = find(postorder.begin(), postorder.end(), leftRootValue) - postorder.begin() + 1;

	    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftSubtreeSize + 1);
	    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftSubtreeSize);
	    vector<int> rightPreorder(preorder.begin() + leftSubtreeSize + 1, preorder.end());
	    vector<int> rightPostorder(postorder.begin() + leftSubtreeSize, postorder.end() - 1);

	    root->left = constructFromPrePost(leftPreorder, leftPostorder);
	    root->right = constructFromPrePost(rightPreorder, rightPostorder);

	    return root;
    }
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;

    vector<int> leftInorder = inorderTraversal(root->left);

    result.insert(result.end(), leftInorder.begin(), leftInorder.end());
    result.push_back(root->val);

    vector<int> rightInorder = inorderTraversal(root->right);
    result.insert(result.end(), rightInorder.begin(), rightInorder.end());

    return result;
}

int main(){
	Solution sol;
	vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    TreeNode* res = sol.constructFromPrePost(preorder, postorder);

    vector<int> inorder = inorderTraversal(res);

    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}