/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int sumNumbers(TreeNode *root) {
return traverse(0, root);
}

int traverse(int fathers, TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    
    int cur = fathers * 10 + root->val;
    
    int sum = traverse(cur, root->left) + traverse(cur, root->right);
    
    return (sum != 0) ? sum : cur;
}
};