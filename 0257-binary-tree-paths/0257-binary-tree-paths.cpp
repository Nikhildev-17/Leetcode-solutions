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
    void helper(TreeNode* root, vector<string>& ans, string s){
        if(root -> right == NULL && root -> left == NULL){
            ans.push_back(s);
            return;
        }
        if(root -> left){
            helper(root -> left, ans, s + "->" + to_string(root -> left -> val));
        }
        if(root -> right){
            helper(root -> right, ans, s + "->" + to_string(root -> right -> val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root -> val);
        helper(root, ans, path);
        return ans;
    }
};