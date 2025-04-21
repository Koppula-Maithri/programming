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
void par(unordered_map<TreeNode*,TreeNode*>&p,TreeNode* root){
    if(root==NULL){
        return;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode *tt=q.front();
        q.pop();
        if(tt->left){
            p[tt->left]=tt;
            q.push(tt->left);
        }
        if(tt->right){
            p[tt->right]=tt;
            q.push(tt->right);
        }
    }
}
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL){
            return false;
        }
        unordered_map<TreeNode*,int>mpp;
        mpp[root]=0;
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*>p;
        par(p,root);
        TreeNode *t1,*t2;
        while(!q.empty()){
         TreeNode *tt=q.front();
            if(tt->val==x){
                t1=tt;
            }
            if(tt->val==y){
                t2=tt;
            }
            q.pop();
            int l=mpp[tt];
            if(tt->left){
                mpp[tt->left]=l+1;
                q.push(tt->left);
            }
            if(tt->right){
                mpp[tt->right]=l+1;
                q.push(tt->right);
            }
        }
        return mpp[t1]==mpp[t2] && (p[t1]!=p[t2]);
        
    }
};