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

//SECOND TRIAL
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty())
            return b;
        else if(b.empty())
            return a;
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.length()<b.length())
            swap(a, b);
        int i = 0, carry = 0;
        for(; i<b.length(); ++i)
        {
            if(a[i]=='0' && b[i]=='0')
            {
                if(carry)
                    ans += '1';
                else
                    ans += '0';
                carry = 0;
            }
            else if(a[i]=='1' && b[i]=='1')
            {
                if(carry)
                    ans += '1';
                else
                    ans += '0';
                carry = 1;
            }
            else
            {
                if(carry)
                    ans += '0';
                else
                    ans += '1';
            }
        }
        if(carry)
        {
            for(; i<a.length(); ++i)
            {
                if(carry)
                {
                    if(a[i]=='1')
                        ans+='0';
                    else
                    {
                        ans += '1';
                        carry = 0;
                    }
                }
                else
                    break;
            }
        }
        if(i<a.length())
            ans += a.substr(i);
        else if(carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
