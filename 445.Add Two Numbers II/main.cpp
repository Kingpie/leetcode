/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2,s3;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        int flag = 0;
        while(!s1.empty()&&!s2.empty()){
            int top = s1.top()+s2.top()+flag;
            if(top>= 10){
                top = top%10;
                flag = 1;
            }else{
                flag = 0;
            }
            s3.push(top);
            s1.pop();
            s2.pop();
        }

        stack<int> left = s1.empty() ? s2:s1;
        while(!left.empty()){
            int top = left.top()+flag;
            if(top >= 10){
                top = top%10;
                flag = 1;
            }else{
                flag = 0;
            }
            left.pop();
            s3.push(top);
        }

        if(flag){
            s3.push(1);
        }

        ListNode* ans = new ListNode(0);
        auto temp = ans;
        while(!s3.empty()){
            temp->next = new ListNode(s3.top());
            s3.pop();
            temp = temp->next;
        }
        return ans->next;
    }
};
