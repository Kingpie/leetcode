/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//area
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int s1=0,s2=0,max1=0,max2=0;
        int water = 0,sum=0;
        for(int i = 0; i < n;++i){
            if(height[i]>max1){
                max1=height[i];
            }
            if(height[n-i-1]>max2){
                max2 = height[n-i-1];
            }
            s1 += max1;
            s2 += max2;
            sum+=height[i];
        }
        water = s1+s2-max1*n-sum;
        return water;
    }
};

