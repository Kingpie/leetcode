/*Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
 

Constraints:

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/element-appearing-more-than-25-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        if(len==1) return arr[0];
        int pre = arr[0];
        int cnt = 1;
        for(int i = 1; i < len;++i){
            if(arr[i]!=pre)
                cnt=1;
            else
                cnt++;
            pre = arr[i];
            if(cnt>len/4) return arr[i];
        }
        return 0;
    }
};