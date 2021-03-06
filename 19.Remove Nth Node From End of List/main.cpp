/*Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto ans = new ListNode(0);
        ans->next = head;
        auto fast = head;
        auto slow = head;
        ListNode* pre = nullptr;

        while(fast&&n-->0){
            fast = fast->next;
        }

        while(fast){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if(slow == head){
            ans->next = slow->next;
        }else if(slow == nullptr){
            pre->next = nullptr;
        }else{
            pre->next = slow->next;
        }
        return ans->next;
    }
};