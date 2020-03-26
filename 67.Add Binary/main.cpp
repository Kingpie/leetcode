/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size(), bsize = b.size();
        while (asize > bsize)//补齐
        {
            b = '0' + b;
            bsize++;
        }
        while (asize < bsize)
        {
            a = '0' + a;
            asize++;
        }
        int carry = 0;  //进位
        for (int i = asize - 1; i >= 0; i--)
        {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = (sum &1)+'0';//本位数值
            carry = sum / 2;//进位更新
        }
        if (carry > 0)//有溢出
            a = '1' + a;
        return a;
    }
};

