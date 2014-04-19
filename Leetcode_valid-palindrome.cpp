class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        string str;
        for(int i = 0; i <s.length(); ++i)
        {
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9'))
                str+=s[i];
            else if(s[i]>='A'&&s[i]<='Z')
                str+=s[i]-'A'+'a';
        }
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        return rev_str == str;
    }
};
