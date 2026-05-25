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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 0});
        unsigned long long int maxWidth  = 0;
        unsigned long long int stIdx, endIdx;
        while(!q.empty()){
            int currLevelSize = q.size();
            stIdx = q.front().second;
            endIdx = q.back().second;
            maxWidth = max(maxWidth, (endIdx - stIdx + 1));

            for(int i = 0; i<currLevelSize; i++){
                TreeNode* curr = q.front().first;
                unsigned long long int currIdx = q.front().second;
                q.pop();
                if(curr -> left) q.push({curr -> left, 2 * currIdx + 1});
                if(curr -> right) q.push({curr -> right, 2 * currIdx + 2});
            }

        }

        return maxWidth;
    }
};