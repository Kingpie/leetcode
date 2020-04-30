/*Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int i2=0,i3=0,i5=0;
        vector<int> ans = {1};
        int cnt = 1;
        while(cnt++<n){
            int ugly = min(ans[i2]*2,min(ans[i3]*3,ans[i5]*5));
            ans.push_back(ugly);
            if(ugly==ans[i2]*2) i2++;
            if(ugly==ans[i3]*3) i3++;
            if(ugly==ans[i5]*5) i5++;
        }
        return ans[n-1];
    }
};