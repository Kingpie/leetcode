/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
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
    bool isBalanced(TreeNode* root) {
        return TreeHeight(root) != -1;
    }

    int TreeHeight(TreeNode* root) {
        // Base case
        if(!root) return 0; // Empty subtree: define the ground height as 0
        if(!root -> left && !root -> right) return 1; // Leaf node: define as 1

        // If left subtree is unbalanced, we don't need to compute for right subtree
        int left_subtree_height = TreeHeight(root -> left);
        if(left_subtree_height < 0) return -1;

        // If right subtree is unbalanced, we don't need to compare subtrees' heights
        int right_subtree_height = TreeHeight(root -> right);
        if(right_subtree_height < 0) return -1;

        // Verify the balance condition
        if(abs(left_subtree_height - right_subtree_height) > 1) return -1;

        return max(left_subtree_height, right_subtree_height) + 1;
    }
};


