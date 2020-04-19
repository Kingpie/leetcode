/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int len1 = num1.size(),len2=num2.size();
        int n1=0,n2=0,flag=0,multi=0;
        string ans;
        vector<int> temp(len1+len2,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i = 0; i <len1 ; ++i){
            for(int j=0; j<len2; ++j){
                multi = (num1[i]-'0')*(num2[j]-'0');
                temp[i+j]+=multi;
            }
        }

        for(int i = 0; i <len1+len2;++i){
            if(temp[i]>9){
                temp[i+1] += temp[i]/10;
                temp[i] = temp[i]%10;
            }
        }

        int idx = temp[len1+len2-1]==0?len1+len2-2:len1+len2-1;
        for(;idx>=0;idx--)
            ans.push_back(temp[idx]+'0');

        return ans;
    }
};