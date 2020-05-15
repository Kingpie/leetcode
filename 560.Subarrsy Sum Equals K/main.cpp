/*Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//prefix sum and hashmap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0,cnt = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for(int i = 0; i < len;++i){
            sum += nums[i];
            if(m.count(sum-k))
                cnt += m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};

//force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int cnt = 0;
        for(int i = 0; i < len; ++i){
            int sum = 0;
            for(int j = i; j < len; ++j){
                sum += nums[j];
                if(sum == k)
                    cnt++;
            }
        }
        return cnt;
    }
};

