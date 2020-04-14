/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        auto temp = head;
        unordered_map<int,int> mp;
        while(temp){
            mp[temp->val]++;
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        temp = head;
        ListNode* pre = dummy;
        while(temp){
            if(mp[temp->val]>1){
                pre->next = temp->next;
            }else{
                pre = temp;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
