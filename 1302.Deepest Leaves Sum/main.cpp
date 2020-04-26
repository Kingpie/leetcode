/*Given a binary tree, return the sum of values of its deepest leaves.
 

Example 1:



Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/deepest-leaves-sum
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
    int maxLevel = 0;
    int sum = 0;
public:
    void dfs(TreeNode* node,int level){
        if(node){
            if(node->left == nullptr && node->right == nullptr){
                if(level>maxLevel){
                    sum=node->val;
                }else if(level == maxLevel){
                    sum+=node->val;
                }
                maxLevel = max(level,maxLevel);
            }
            dfs(node->left,level+1);
            dfs(node->right,level+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,1);
        return sum;
    }
};