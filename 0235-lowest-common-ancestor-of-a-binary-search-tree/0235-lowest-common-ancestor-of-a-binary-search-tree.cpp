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
TreeNode* leftCA;
TreeNode* rightCA;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root -> val == p -> val || root -> val == q -> val) return root;

        if((root -> val > p -> val && root -> val < q -> val) || (root -> val < p -> val && root -> val > q -> val)) return root;
         
        if(root -> val > p -> val && root -> val > q -> val){
            leftCA = lowestCommonAncestor(root -> left, p, q);
        }
        if(root -> val < p -> val && root -> val < q -> val){
            rightCA = lowestCommonAncestor(root -> right, p, q);
        }

        if(leftCA != NULL) return leftCA;
        return rightCA;
    }
};