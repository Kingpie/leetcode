/*A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Example:

Input:

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6

Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance
             of 2+2+2=6 is minimal. So return 6.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-meeting-point
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        vector<int> rows,columns;
        for(int i = 0; i < m;++i){
            for(int j = 0; j < n;++j){
                if(grid[i][j]==1){
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        int x = rows[rows.size()/2];
        sort(columns.begin(),columns.end());
        int y = columns[columns.size()/2];

        int sum = 0;
        for(auto t:rows){
            sum += abs(t-x);
        }

        for(auto t:columns){
            sum += abs(t-y);
        }

        return sum;
    }
};
