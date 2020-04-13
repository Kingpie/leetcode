/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto temp1 = l1;
        auto temp2 = l2;
        int size1=0,size2=0;
        while(temp1){
            size1++;
            temp1=temp1->next;
        }
        while(temp2){
            size2++;
            temp2=temp2->next;
        }

        ListNode* big = nullptr;
        ListNode* small = nullptr;

        if(size1>size2){
            big = l1;
            small = l2;
        }else{
            small = l1;
            big = l2;
        }

        auto ans = big;
        int flag = 0;
        while(small){
            big->val = small->val+big->val+flag;
            if(big->val > 9){
                big->val = big->val%10;
                flag = 1;
            }else{
                flag = 0;
            }

            if(big->next == nullptr&&flag){
                big->next = new ListNode(1);
                return ans;
            }

            small = small->next;
            big = big->next;
        }

        while(big){
            if(!flag)
                break;
            big->val += flag;
            if(big->val>9){
                big->val = big->val%10;
            }else{
                flag = 0;
            }

            if(big->next == nullptr&&flag){
                big->next = new ListNode(1);
                return ans;
            }

            big = big->next;
        }

        return ans;
    }
};

