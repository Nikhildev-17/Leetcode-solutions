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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    bool isFirst = true;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        
        inorder(root -> left);
        if(prev && root -> val < prev -> val){
            if(isFirst){
                first = prev;
                second = root;
                isFirst = false;
                
            }else{
                second = root;
            }
        }
        prev = root;
        inorder(root -> right);
    }
    void recoverTree(TreeNode* root) {
    
        inorder(root);
        if(first && second) swap(first -> val, second -> val);

    }
};