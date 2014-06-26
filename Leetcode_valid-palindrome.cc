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

//SECOND TRIAL
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int cnt = 0;
        for(int i = 0; i<s.length(); ++i)
        {
            if((s[i]>='0' && s[i]<='9')||(s[i]>='a' &&s[i]<='z'))
                s[cnt++] = s[i];
            else if(s[i]>='A' && s[i]<='Z')
                s[cnt++] = s[i] + 'a' - 'A';
        }
        s = s.substr(0, cnt);
        string revs(s.rbegin(), s.rend());
        return revs==s;
    }
};
