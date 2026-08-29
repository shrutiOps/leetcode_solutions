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
    bool isBalanced(TreeNode* root) {
        return dps(root) != -1;
    }
    int dps(TreeNode * root){
        if( root == NULL) return 0;
        int lh = dps(root->left);
        int rh = dps(root->right);
        if( lh == -1) return -1;
        if( rh == -1) return -1;
        if(abs(lh - rh) > 1) return -1;
        return max(lh, rh)+1;
    }
};