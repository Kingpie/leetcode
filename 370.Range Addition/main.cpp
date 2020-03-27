/*Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]
Explanation:

Initial state:
[0,0,0,0,0]

After applying operation [1,3,2]:
[0,2,2,2,0]

After applying operation [2,4,3]:
[0,2,5,5,3]

After applying operation [0,2,-2]:
[-2,0,3,5,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-addition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> temp(length);
        for(int i = 0; i < updates.size();++i){
            temp[updates[i][0]] += updates[i][2];
            if(updates[i][1]+1<length)
                temp[updates[i][1]+1] -= updates[i][2];
        }
        for(int i = 1; i < length;++i){
            temp[i] += temp[i-1];
        }
        return temp;
    }
};

