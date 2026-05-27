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
    int pathSum = INT_MIN;
    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int leftSum = max(0, helper(root -> left));
        int rightSum = max(0, helper(root -> right));

        int bestSum = max(leftSum, rightSum);
        int curr = leftSum + rightSum + root -> val;

        pathSum = max(pathSum, curr);

        return bestSum + root -> val;
    } 

    int maxPathSum(TreeNode* root) {
        int x = helper(root);
        return pathSum;
    }
};