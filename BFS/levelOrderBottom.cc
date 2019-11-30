class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> result;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while (!Q.empty()) {
            vector<int> level;
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* head = Q.front();
                Q.pop();
                level.push_back(head->val);
                if (head->left != NULL) {
                    Q.push(head->left);
                }
                if (head->right != NULL) {
                    Q.push(head->right);
                }
            }
            result.push_back(level);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
