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
bool helper(TreeNode* root,int targetSum,int curr){
    if(root==nullptr){
        return true;
    }
    curr+=root->val;
    if(curr==targetSum && !root->right && !root->left){
        return true;
    }
    if(curr!=targetSum && !root->right && !root->left){
        return false;
    }
    return helper(root->left,targetSum,curr)||helper(root->right,targetSum,curr);
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return false;
        }
     return helper(root,targetSum,0);
    }
};