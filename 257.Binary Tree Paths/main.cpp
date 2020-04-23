/*Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
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
    vector<int> record;
    vector<string> ans;
public:
    void dfs(TreeNode* node){
        if(node){
            record.push_back(node->val);
            if(node->left==nullptr&&node->right==nullptr){
                string temp(to_string(record[0]));
                for(int i = 1; i < record.size();++i){
                    temp+="->"+to_string(record[i]);
                }
                ans.push_back(temp);
            }
            dfs(node->left);
            dfs(node->right);
            record.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};