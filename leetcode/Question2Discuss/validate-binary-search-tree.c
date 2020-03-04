// URL: https://leetcode.com/problems/validate-binary-search-tree/submissions/

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
Wrong Ans for [5, 14, NULL, 1]
*/
class Solution1 {
public:
    bool isBST(TreeNode* root, int min, int max) {
        if (!root) return true;
        else if (!(root->left) && !(root->right)) return true;
        else if (!(root->left))
            return (root->val < max && isBST(root->right, root->val, max));
        else if (!(root->right))
            return (root->val > min && isBST(root->left, min, root->val));
        else
            return (root->val > min && root->val < max && \
                    isBST(root->left, min, root->val) && \
                    isBST(root->right, root->val, max));
    }
    bool isValidBST(TreeNode* root) {
        int min, max; TreeNode* _root = NULL;
        
        _root = root;
        while(_root) {min = _root->val; _root = _root->left;}
        _root = root;
        while(_root) {max = _root->val; _root = _root->right;}
        
        return isBST(root, min, max);
    }
};

/*
Wrong Ans for [1, 1]
*/
class Solution2 {
public:
    bool isBST(TreeNode* root, int min, int max) {
        if (!root) return true;
        else
            return (root->val >= min && root->val <= max && \
                    isBST(root->left, min, root->val) && \
                    isBST(root->right, root->val, max));
    }
    bool isValidBST(TreeNode* root) {
        int min, max; TreeNode* _root = NULL;
        
        _root = root;
        while(_root) {min = _root->val; _root = _root->left;}
        _root = root;
        while(_root) {max = _root->val; _root = _root->right;}
        
        return isBST(root, min, max);
    }
};

/*
Runtime: 8 ms, faster than 98.51% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 20 MB, less than 97.92% of C++ online submissions for Validate Binary Search Tree.
*/
// In-Order Traversal
class Solution {
public:
    vector<int> in_order;
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        in_order.push_back(root->val);
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        in_order.clear();
        inOrder(root);
        if(in_order.size() <= 1) return true;
        for(int i=1; i<in_order.size(); i++)
            if(in_order[i-1]>=in_order[i]) return false;
        return true;
    }
};
