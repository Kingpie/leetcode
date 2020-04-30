/*Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-primes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(n,true);
        int cnt = 0;
        for(int i = 2; i < n;++i){
            if(flag[i]){
                cnt++;
                for(int j = i+i;j<n;j+=i){
                    flag[j]=false;
                }
            }
        }
        return cnt;
    }
};