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
    void helper(TreeNode* root, int& height, int& maxHeight) {
        if(!root)
            return;
        height++;
        helper(root->left, height, maxHeight);
        helper(root->right, height, maxHeight);
        maxHeight = max(maxHeight,height);
        height--;
        
    }
    int maxDepth(TreeNode* root) {
        int maxHeight = 0;
        int height = 0;
        helper(root, height, maxHeight);
        return maxHeight;
    }
};