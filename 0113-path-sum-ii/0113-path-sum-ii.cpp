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
void helper(TreeNode* root,vector<int>&temp,vector<vector<int>>&ans,int tar,int curr){
    if(root==nullptr){
        return;
    }
    temp.push_back(root->val);
    curr=curr+root->val;
    if(!root->right && !root->left){
        if(curr==tar){
            ans.push_back(temp);
        }
    }
    helper(root->left,temp,ans,tar,curr);
    helper(root->right,temp,ans,tar,curr);
     temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(root,temp,ans,targetSum,0);
        return ans;
    }
};