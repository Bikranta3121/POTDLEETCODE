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
    
    int getMinimumDifference(TreeNode* root) {
        
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        int min_diff=INT_MAX;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            ans.push_back(temp->val);
            q.pop();
            if(temp->left)
            {
             
               q.push(temp->left);
            }
            if(temp->right)
            {
             
                q.push(temp->right);
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=1;i<ans.size();i++)
        {
            min_diff=min(min_diff,ans[i]-ans[i-1]);
        }
        return min_diff;

    }
};
