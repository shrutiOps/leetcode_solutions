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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);

        sort(sizes.rbegin(), sizes.rend());

        if (sizes.size() < k)
            return -1;

        return sizes[k - 1];
    }

private:
    vector<int> sizes;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == -1 || right == -1 || left != right)
            return -1;

        int size = left + right + 1;
        sizes.push_back(size);

        return size;
    }
};