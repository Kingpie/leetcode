/*Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
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
        auto ans = head;
        unordered_set<int> st;
        ListNode* pre = nullptr;
        while(head){
            if(st.count(head->val)){
                pre->next = pre->next->next;
                head = head->next;
                continue;
            }

            st.insert(head->val);
            pre = head;
            head = head->next;
        }
        return ans;
    }
};
