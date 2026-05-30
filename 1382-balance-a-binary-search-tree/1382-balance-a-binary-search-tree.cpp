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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;

        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);
    }
    TreeNode* helper(vector<int>& nums, int st, int end){

        if(st > end) return NULL;
        
        int mid = st + (end-st)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root -> left = helper(nums, st, mid - 1);
        root -> right = helper(nums, mid + 1, end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);

        return helper(ans, 0, ans.size()-1);
    }
};