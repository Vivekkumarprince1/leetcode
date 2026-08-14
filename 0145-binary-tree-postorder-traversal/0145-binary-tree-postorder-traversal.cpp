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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*> st,st1;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            st1.push(node);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);

        }            while(!st1.empty()){
                ans.push_back(st1.top()->val);
                st1.pop();
            }

        return ans;
    }
};