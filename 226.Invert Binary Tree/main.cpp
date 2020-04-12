/*Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invert-binary-tree
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            auto temp = node->left;
            node->left = node->right;
            node->right = temp;

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return root;
    }
};

//stack
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        stack<TreeNode*> s;
        if(root)
            s.push(root);

        while(!s.empty()){
            auto node = s.top();
            s.pop();

            if(node == nullptr)
                continue;
            swap(node->left, node->right);
            s.push(node->left);
            s.push(node->right);
        }
        return root;
    }
};

