/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int,ListNode*> m;

        for(int i = 0; i < lists.size();++i){
            while(lists[i]){
                m.insert(make_pair(lists[i]->val,lists[i]));
                lists[i]=lists[i]->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        auto temp = dummy;
        for(auto it = m.begin();it!=m.end();++it){
            it->second->next=nullptr;
            temp->next = it->second;
            temp=temp->next;
        }
        return dummy->next;
    }
};