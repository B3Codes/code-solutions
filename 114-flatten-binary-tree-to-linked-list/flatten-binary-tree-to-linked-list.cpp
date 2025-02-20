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
//Brutt force solution (pre-order traversal)
    void preOrder(TreeNode* root, vector<int>& nodes) {
        if(root == NULL)
            return;
        // cout<<root->val<<" ";
        nodes.push_back(root->val);
        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
    }
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        vector<int> nodes;
        preOrder(root, nodes);
        TreeNode* tempRoot = root;
        for(int i = 0 ;i<nodes.size()-1;i++) {
            tempRoot->left = NULL;
            TreeNode* temp =  new TreeNode(nodes[i+1]);
            tempRoot->right = temp;
            tempRoot = temp;
        
        }


    }
};