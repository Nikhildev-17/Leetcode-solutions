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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        inorder(root1, v1);
        inorder(root2, v2);
        vector<int> ans;
        int i=0,j=0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i] >= v2[j]){
                ans.push_back(v2[j]);
                j++;
            }else{
                ans.push_back(v1[i]);
                i++;
            }
        }
        while(i < v1.size())ans.push_back(v1[i++]);
        while(j < v2.size()) ans.push_back(v2[j++]);

        return ans;
    }
};