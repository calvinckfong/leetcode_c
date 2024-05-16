/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 2331. Evaluate Boolean Binary Tree
bool evaluateTree(struct TreeNode* root) {
    if (root->val<2) 
        return (root->val==1);
    
    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);
    
    return (root->val==2)?(left||right):(left&&right);
}
