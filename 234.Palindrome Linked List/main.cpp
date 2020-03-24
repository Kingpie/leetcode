/*Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//time O(n),space O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto fast = head;
        auto slow = head;
        ListNode* pre = NULL;

        while(fast && fast->next){
            fast = fast->next->next;

            auto temp = pre;
            pre = slow;
            slow = slow->next;
            pre->next = temp;
        }

        if(fast)
            slow = slow->next;

        while(pre && slow){
            if(pre->val != slow->val)
                return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};

//time O(n) spaceO(n)
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        int temp = 0;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }

        int len = vec.size();
        for(auto i = 0; i < vec.size(); ++i)
        {
            if(vec[i] != vec[len-i-1])
                return false;
        }
        return true;
    }
};


