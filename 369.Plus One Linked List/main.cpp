/*Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example :

Input: [1,2,3]
Output: [1,2,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//stack
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<int> stk,result;
        while(head){
            stk.push(head->val);
            head = head->next;
        }

        int flag = 1;
        while(!stk.empty()){
            int top = stk.top()+flag;
            if(top>=10){
                top = top%10;
                flag = 1;
            }else{
                flag = 0;
            }
            stk.pop();
            result.push(top);
        }

        if(flag)
            result.push(1);

        ListNode* ans = new ListNode(0);
        auto temp = ans;
        while(!result.empty()){
            temp->next = new ListNode(result.top());
            result.pop();
            temp = temp->next;
        }
        return ans->next;
    }
};
