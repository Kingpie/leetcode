/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//partition
class Solution {
public:
    int partition(vector<int>& nums,int start,int end){
        if(start == end) return start;
        int n = nums[start];
        while(start < end){
            while(start<end && nums[end]>n){
                end--;
            }
            nums[start]=nums[end];
            while(start<end&& nums[start]<=n){
                start++;
            }
            nums[end]=nums[start];
        }
        nums[end] = n;
        return end;
    }
    int majorityElement(vector<int>& nums) {
        int mid = nums.size()/2;
        int start = 0,end=nums.size()-1;
        while(true){
            int pivot = partition(nums,start,end);
            if(pivot == mid) return nums[mid];
            else if(pivot>mid) end = pivot-1;
            else start = pivot+1;
        }
    }
};