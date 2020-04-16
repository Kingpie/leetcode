/*Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int flag = 0;
        for(auto t : nums){
            flag ^= t;
        }

        flag = flag&(-flag);

        vector<int> ans(2,0);
        for(auto t:nums){
            if(t&flag){
                ans[0] ^= t;
            }else{
                ans[1] ^= t;
            }
        }
        return ans;
    }
};