/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        int flag = 0;
        TreeNode* prev = NULL;
        TreeNode* p0, *p1;
        
        helper(root, flag, prev, p0, p1);
        
        swap(p0->val, p1->val);    
    }
    
    void helper(TreeNode* root, int& flag, TreeNode*& prev, TreeNode*& p0, TreeNode*& p1) {
        if (root == NULL) {
            return;
        }
        
        helper(root->left, flag, prev, p0, p1);
        
        if (flag == 2) {
            return;
        }
        
        if (prev != NULL && prev->val > root->val && flag == 0) {
            p0 = prev;
            p1 = root;
            flag++;
        } else if (prev != NULL && prev->val > root->val && flag == 1) {
            p1 = root;
            flag++;
            return;
        }
        
        prev = root;
        helper(root->right, flag, prev, p0, p1);
    }
};
