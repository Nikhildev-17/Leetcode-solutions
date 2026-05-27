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
    int ans = 0;
    void helper(TreeNode* root, int num){
        if(root == NULL) return;

        if(root -> left == NULL && root -> right == NULL){
            num = num * 10 + root -> val;
            ans += num;
            return;
        }

        num = num * 10 + root -> val;
        helper(root -> left, num);
        helper(root -> right, num);

    }
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
};