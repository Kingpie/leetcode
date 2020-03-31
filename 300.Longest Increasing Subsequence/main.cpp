/*Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> dp(len,1);
        int maxi = 1;
        for(int i = 0; i < len;++i){
            int maxj = 0;
            for(int j = 0; j < i;++j){
                if(nums[j]<nums[i])
                    maxj = max(maxj,dp[j]);
            }

            dp[i] = maxj+1;
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};
