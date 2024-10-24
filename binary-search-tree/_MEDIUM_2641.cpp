#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* modifiedRoot = root;

        return modifiedRoot;
    }

    void preOrderTraversal(TreeNode* root) {
        if(root != nullptr) {
            cout << root->val << "->";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode();
    root->right->right = new TreeNode(7);

    Solution s;
    TreeNode* newRoot = s.replaceValueInTree(root);
    s.preOrderTraversal(root);
    return 0;
}