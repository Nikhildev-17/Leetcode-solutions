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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot == NULL) return root == subRoot;

        bool leftSame = isSame(root -> left, subRoot -> left);
        bool rightSame = isSame(root -> right, subRoot -> right);

        return leftSame && rightSame && root -> val == subRoot -> val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL) return root == subRoot;

        if(root -> val == subRoot -> val && isSame(root, subRoot)) return true;

        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};