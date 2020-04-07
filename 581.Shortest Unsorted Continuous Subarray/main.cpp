/*Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        int high = 0,low = len -1,max_num=nums[0],min_num=nums[len-1];
        for(int i = 1; i < len; ++i){
            max_num = max(max_num,nums[i]);
            min_num = min(min_num,nums[len-i-1]);
            if(nums[i] < max_num)
                high = i;
            if(nums[len-i-1]>min_num)
                low = len-i-1;
        }
        return high > low?high-low+1:0;
    }
};

//stack
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        stack<int> s;
        int l = len,r=0;
        for(int i = 0; i < len; ++i){
            while(!s.empty() && nums[s.top()]>nums[i]){
                l = min(l,s.top());
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty())
            s.pop();

        for(int i = len-1; i >=0;i--){
            while(!s.empty() && nums[s.top()]<nums[i]){
                r = max(r,s.top());
                s.pop();
            }
            s.push(i);
        }
        return r>l ? r-l+1:0;
    }
};