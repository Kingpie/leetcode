/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return true;

        vector<int> dp(len,0);
        dp[0] = nums[0];
        for(int i = 1; i < len;++i){
            if(i <= dp[i-1]){
                dp[i] = max(dp[i-1],i+nums[i]);
            }
        }
        return dp[len-2]>=len-1;
    }
};

