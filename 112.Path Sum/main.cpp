/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
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
    void dfs(TreeNode* node,int cur,int sum,bool& exist){
        if(!node->right&&!node->left){
            if(cur==sum)
                exist = true;
            return;
        }

        if(node->right) dfs(node->right,cur+node->right->val,sum,exist);
        if(node->left) dfs(node->left,cur+node->left->val,sum,exist);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        bool exist =false;
        dfs(root,root->val,sum,exist);
        return exist;
    }
};