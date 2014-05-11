class Solution {
public:
    string addBinary(string a, string b) {
        char ch[]="01";
        if(a.empty())
            return b;
        else if(b.empty())
            return a;
       
        int len1 = a.length() - 1, len2 = b.length() - 1, carry = 0, num1, num2;
        if(len1 < len2)
        {
            string tmp = a;
            a = b;
            b = tmp;
            int c = len1;
            len1 = len2;
            len2 = c;
        }
        string res;
        while(len1>=0 && len2>=0)
        {
            num1 = a[len1--] - '0';
            num2 = b[len2--] - '0';
            if(num1 + num2 + carry >= 2)
            {
                res+=ch[num1 + num2 + carry - 2];
                carry = 1;
            }
            else
            {
                res+=ch[num1 + num2 + carry];
                carry = 0;
            }
        }
        while(len1>=0)
        {
            num1 = a[len1--] - '0';
            if(num1 + carry>=2)
            {
                res+=ch[num1 + carry - 2];
                carry = 1;
            }
            else
            {
                res+=ch[num1 + carry];
                carry = 0;
            }
        }
        if(carry)
        {
            res+='1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
