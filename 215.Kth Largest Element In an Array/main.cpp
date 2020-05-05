/*Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int partition(vector<int>& nums,int start,int end){
        if(start==end) return start;
        int pivot = nums[start];
        while(start<end){
            while(start<end&&nums[end]<pivot){
                end--;
            }
            nums[start]=nums[end];
            while(start<end&&nums[start]>=pivot){
                start++;
            }
            nums[end]=nums[start];
        }
        nums[start]=pivot;
        return start;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int max=nums.size();
        int start = 0;
        int end = max-1;
        int idx = partition(nums,start,end);
        while(idx+1!=k){
            if(idx+1>k){
                end = idx-1;
                idx = partition(nums,start,end);
            }else{
                start=idx+1;
                idx = partition(nums,start,end);
            }
        }
        return nums[idx];
    }
};

