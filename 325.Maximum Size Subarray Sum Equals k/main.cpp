/*Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-size-subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//force
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();
        int maxLen = INT_MIN;
        int sum = 0;
        for(int i = 0; i < len; ++i){
            sum = 0;
            for(int j=i; j < len;++j){
                sum += nums[j];
                if(sum == k)
                    maxLen = max(maxLen,j-i+1);
            }
        }
        return maxLen==INT_MIN?0:maxLen;
    }
};