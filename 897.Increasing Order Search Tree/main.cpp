/*Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-order-search-tree
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
    queue<TreeNode*> q;
public:
    void dfs(TreeNode* node){
        if(node){
            dfs(node->left);
            q.push(node);
            dfs(node->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* dummy = new TreeNode(0);
        auto temp = dummy;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            node->right = nullptr;
            node->left = nullptr;
            temp->right = node;
            temp = temp->right;
        }
        return dummy->right;
    }
};

