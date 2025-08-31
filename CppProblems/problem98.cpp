// Runtime beats 100% memory beats 94.51%

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
    bool isValidBST(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true; 
        return isValidBST(root->left, 'l', LLONG_MIN, root->val) && isValidBST(root->right, 'r', root->val, LLONG_MAX);
    }


private:
    bool isValidBST(TreeNode* root, char prev_dir, long long lower_limit, long long upper_limit) {
        if(root == NULL) return true; 
        if(root->val >= upper_limit || root->val <= lower_limit) return false; 
        if(prev_dir == 'l' && root->val < lower_limit) return false; 
        if(prev_dir == 'r' &&  root->val > upper_limit) return false; 
        return isValidBST(root->left, 'l', lower_limit, root->val) && isValidBST(root->right, 'r', root->val, upper_limit);
    }
};