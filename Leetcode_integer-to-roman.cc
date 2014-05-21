class Solution {
public:
    string intToRoman(int num) {
        char str[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int div = 1000, digit = 0;
        string ans;
        for(int i = 6; i>=0 && num; i-=2)
        {
            digit = num / div;
            num %= div;
            if(digit)
            {
                if(digit<=3)
                   ans.append(digit, str[i]);
                else if(digit == 4)
                {
                    ans.append(1, str[i]);
                    ans.append(1, str[i+1]);
                }
                else if(digit == 5)
                    ans.append(1, str[i+1]);
                else if(digit <= 8)
                {
                    ans.append(1, str[i+1]);
                    ans.append(digit-5, str[i]);
                }
                else if(digit == 9)
                {
                    ans.append(1, str[i]);
                    ans.append(1, str[i+2]);
                }
            }
            div /= 10;
        }
        return ans;
    }
};
