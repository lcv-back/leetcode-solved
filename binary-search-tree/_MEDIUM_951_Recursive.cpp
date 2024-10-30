#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr || root2 == nullptr) return false;
        if(root1->val != root2->val) return false;

        bool noSwap = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool swap = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

        return noSwap || swap;
    }
};

int main(){
	Solution sol;
	// Create tree root1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(8);

    // Create tree root2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->left->right = new TreeNode(6);
    root2->right = new TreeNode(2);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(5);
    root2->right->right->left = new TreeNode(8);
    root2->right->right->right = new TreeNode(7);

    cout << (sol.flipEquiv(root1, root2) ? "True" : "False") << endl;
	return 0;
}