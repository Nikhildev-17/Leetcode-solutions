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
    void helper(TreeNode* root, int targetSum, vector<int>& paths, vector<vector<int>>& ans){
        if(root == NULL) return;
        if((root -> left == NULL && root -> right == NULL) && targetSum - root -> val == 0){
            paths.push_back(root -> val);
            ans.push_back(paths);
            paths.pop_back();
            return;
        }
        paths.push_back(root -> val);
        helper(root -> left, targetSum - root -> val, paths, ans);
        
        helper(root -> right, targetSum - root -> val, paths, ans);
        paths.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> paths;
        vector<vector<int>> ans;
        helper(root, targetSum, paths, ans);
        return ans;
    }
};