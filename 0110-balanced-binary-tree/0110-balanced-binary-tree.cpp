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
    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = helper(root -> left);
        int rightHeight = helper(root -> right);

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int leftHt = helper(root -> left);
        int rightHt = helper(root -> right);

        if(abs(leftHt - rightHt) <= 1 && isBalanced(root -> left) && isBalanced(root -> right)){
            return true;
        }

        return false;
    }
};