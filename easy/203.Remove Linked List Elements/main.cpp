/*Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-linked-list-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//aided head node
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto result = new ListNode(0);
        result->next = head;
        auto temp = result;
        while(temp->next){
            if(temp->next->val == val){
                auto del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }else{
                temp = temp->next;
            }
        }
        return result->next;
    }
};

