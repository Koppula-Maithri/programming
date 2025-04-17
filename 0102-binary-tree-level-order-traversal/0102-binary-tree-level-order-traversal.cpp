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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return {};
        }
        TreeNode *dummy=new TreeNode(-1);
        queue<TreeNode*>q;
        q.push(root);
        q.push(dummy);
        vector<int>temp;
        while(!q.empty()){
            TreeNode *nn=q.front();
             q.pop();
            if(nn==dummy){
                 if(!q.empty()){
                    ans.push_back(temp);
                    temp.clear();
                    q.push(dummy);
                 }
                 else{
                    break;
                 }
            }
            else{
                temp.push_back(nn->val);
                if(nn->left!=NULL){
                q.push(nn->left);
                }
                if(nn->right!=NULL){
                q.push(nn->right);
            }
            }
        }
        ans.push_back(temp);
        return ans;
    }
};