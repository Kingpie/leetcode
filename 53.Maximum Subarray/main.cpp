/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class SolutionForce {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int max = INT_MIN;
        for(int i = 0; i < len; ++i){
            sum = 0;
            for(int j = i; j < len; ++j){
                sum += nums[j];
                if(sum > max)
                    max = sum;
            }
        }
        return max;
    }
};

class SolutionDP {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        int dp = nums[0];
        int maxNum = dp;
        for(int i = 1; i < len; ++i){
            dp = max(nums[i],dp+nums[i]);
            maxNum = max(maxNum,dp);
        }
        return maxNum;
    }
};

class SolutionMerge {
public:
    int crossNum(vector<int>& nums,int start,int end,int mid){
        int sum = 0,lmax = INT_MIN,rmax = INT_MIN;
        for(int i = mid; i >= start; i--){
            sum += nums[i];
            lmax = max(sum,lmax);
        }

        sum = 0;
        for(int i = mid+1;i <= end;++i){
            sum += nums[i];
            rmax = max(sum,rmax);
        }
        return lmax+rmax;
    }

    int helper(vector<int>& nums,int start,int end){
        if(end == start) return nums[start];
        int mid = (start+end)/2;

        int lsum = helper(nums,start,mid);
        int rsum = helper(nums,mid+1,end);
        int msum = crossNum(nums,start,end,mid);

        return max(max(lsum,rsum),msum);
    }

    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        return helper(nums, 0, len-1);
    }
};

class SolutionGreedy {
public:
    int maxSubArray(vector<int>& nums){
        int len = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < len; ++i){
            sum += nums[i];
            maxSum = max(sum,maxSum);

            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};