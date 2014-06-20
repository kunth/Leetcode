class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        if(num1=="1")
            return num2;
        if(num2=="1")
            return num1;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int sum = 0, carry = 0;
        string ans;
        for(int i = 0; i<num1.length()+num2.length(); ++i)
        {
            sum = 0;
            for(int j = 0; j<=i; ++j)
            {
                if(j<num1.length() && i-j<num2.length())
                    sum += (num1[j]-'0') * (num2[i-j]-'0');
            }
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            ans += sum+'0';
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        for(; i<ans.length(); ++i)
            if(ans[i]!='0')
                break;
        return ans.substr(i);
    }
};
