/*Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/*dp[i][0]={
    dp[i−1][0]+1,nums[i]=1
    0,nums[i]=0
}

dp[i][1]={
    dp[i−1][1]+1,nums[i]=1
    dp[i−1][0]+1,nums[i]=0
}
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int dp0 = 0,dp1 = 0,maxCount = 0;
        for(int i = 0; i < len;++i){
            if(nums[i]){
                dp0++;
                dp1++;
            }else{
                dp1 = dp0+1;
                dp0 = 0;
            }
            maxCount = max(maxCount,max(dp0,dp1));
        }
        return maxCount;
    }
};

