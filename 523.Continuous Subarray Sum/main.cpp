/*Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

 

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
 

Note:

The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/continuous-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//force
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if(len < 2) return false;

        for(int i = 0; i < len;++i){
            int sum = 0;
            for(int j = i; j < len;++j){
                sum += nums[j];
                if(j-i+1 >= 2){
                    if(k==0){
                        if(sum == 0)
                            return true;
                    }else{
                        if(sum%k==0)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};

//prefix sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if(len < 2) return false;
        if(k==0){
            for(int i = 1; i < len;++i){
                if(nums[i] == 0 && nums[i-1] == 0)
                    return true;;
            }
            return false;
        }

        k = abs(k);
        unordered_set<int> s{0};
        int t = nums[0]%k;

        for(int i = 1; i < len;++i){
            int t1 = t;
            t = (t+nums[i])%k;
            if(s.count(t)) return true;
            s.insert(t1);
        }
        return false;
    }
};