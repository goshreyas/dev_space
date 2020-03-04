/*
 * URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
Runtime: 28 ms, faster than 85.39% of C++ online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 24 MB, less than 96.97% of C++ online submissions for Binary Tree Maximum Path Sum.
*/
 
class Solution {
public:
    int maxSum = INT_MIN;
    int max_sum(TreeNode* root) {
        if(!root) return 0;
        int max_left, max_right, mxl, mxr, mx;
        max_left = max_sum(root->left);
        mxl = max(root->val, root->val+max_left);
        max_right = max_sum(root->right);
        mxr = max(mxl, root->val+max_right);
        mx = max(mxr, root->val+max_left+max_right);
        maxSum = max(mx, maxSum);
        return mxr;
    }
    int maxPathSum(TreeNode* root) {
        max_sum(root);
        return maxSum;
    }
};
