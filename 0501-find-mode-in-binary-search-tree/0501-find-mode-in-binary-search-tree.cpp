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
    vector<int> modes;
    int maxCount = 0, currCount = 0;
    TreeNode* prev = nullptr;
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev == nullptr || prev->val != node->val) {
            currCount = 1;
        } else {
            currCount++;
        }
        if (currCount > maxCount) {
            maxCount = currCount;
            modes.clear();
            modes.push_back(node->val);
        } else if (currCount == maxCount) {
            modes.push_back(node->val);
        }
        prev = node;
        inorder(node->right);
    }
};
