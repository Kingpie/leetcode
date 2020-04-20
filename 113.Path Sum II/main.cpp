/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
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
class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& q,TreeNode* node,int sum){
        if(!node) return;
        q.push_back(node->val);
        sum -= node->val;
        if(!node->right&&!node->left){
            if(0 == sum){
                ans.push_back(q);
            }
        }else{
            dfs(ans,q,node->right,sum);
            dfs(ans,q,node->left,sum);
        }

        q.pop_back();
        sum += node->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> vec;
        dfs(ans,vec,root,sum);
        return ans;
    }
};