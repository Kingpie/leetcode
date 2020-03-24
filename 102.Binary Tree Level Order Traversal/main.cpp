/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return {};

        vector<vector<int>> result;
        q.push(root);
        while(!q.empty()){
            int curLevelNum = q.size();
            vector<int> vec;

            while(curLevelNum-- > 0){
                auto node = q.front();

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }

                vec.push_back(node->val);

                q.pop();
            }
            result.push_back(vec);
        }
        return result;
    }
};