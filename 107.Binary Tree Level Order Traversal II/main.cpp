/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> res;
        if(root==NULL)return res;
        queue<TreeNode*> q;
        TreeNode* p;
        q.push(root);

        while(!q.empty())
        {
            vector<int> temp;
            int queueSize=q.size();
            for(int i=0;i<queueSize;++i)
            {
                p=q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
            }
            res.push_back(temp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};