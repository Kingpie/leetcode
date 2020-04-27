/*Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i = 0; i < grid.size();++i){
            int len = grid[i].size();
            if(grid[i][0]>=0&&grid[i][len-1]>=0)
                continue;

            if(grid[i][0]<0){
                sum+= len;
                continue;
            }

            int start = 0,end=len-1;
            while(start<end){
                int mid = start+(end-start)/2;
                if(grid[i][mid]<0){
                    sum+=end-mid+1;
                    end = mid-1;
                }else{
                    if(mid+1<=len&&grid[i][mid+1]<0){
                        sum+=end-mid;
                        break;
                    }

                    start = mid+1;
                }
            }
        }
        return sum;
    }
};