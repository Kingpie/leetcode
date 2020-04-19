/*Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nth-digit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int findNthDigit(int n) {
        vector<long> vec = {0,9,90*2,900*3,9000*4,90000*5,900000*6,9000000*7,90000000*8,900000000l*9,9000000000l*10};
        vector<long> start = {0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
        int i = 1;
        for(; i < vec.size();++i){
            if(n<=vec[i])
                break;
            else{
                n-=vec[i];
            }
        }

        int pos = n%i;
        if(pos == 0) pos = i;
        long target = start[i]+(pos==i?(n/i)-1:n/i);
        for(int m=pos;m<i;++m) target /= 10;

        return target%10;
    }
};