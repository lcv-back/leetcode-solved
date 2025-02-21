#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
private:
    void recovery(TreeNode* root, int val){
        if(root == nullptr) return;
        root->val = val;
        set.insert(root->val);

        recovery(root->left, 2 * val + 1);
        recovery(root->right, 2 * val + 2);
    }

public:
    unordered_set<int> set;

    FindElements(TreeNode* root){
        recovery(root, 0);
    }

    bool find(int target){
        return set.find(target) != set.end(); 
    }
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);
    root->right->left = new TreeNode(-1);
    root->right->right = new TreeNode(-1);
    return root;
}

int main() {
    TreeNode* root = createTree();

    FindElements obj(root);

    cout << obj.find(3) << endl;
    cout << obj.find(5) << endl;
    cout << obj.find(7) << endl;

    return 0;
}
