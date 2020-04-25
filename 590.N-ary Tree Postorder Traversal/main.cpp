/*Given an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Follow up:

Recursive solution is trivial, could you do it iteratively?

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> ans;
public:
    void dfs(Node* node){
        for(int i = 0; i < node->children.size();++i){
            dfs(node->children[i]);
        }
        ans.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        if(!root) return {};
        dfs(root);
        return ans;
    }
};

//stack
class Solution {
public:

    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node*> s1,s2;
        if(root)
            s1.push(root);
        while(!s1.empty()){
            auto node = s1.top();
            s1.pop();
            s2.push(node);

            for(int i = 0; i < node->children.size();++i){
                s1.push(node->children[i]);
            }
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};