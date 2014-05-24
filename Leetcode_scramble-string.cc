class Solution {
public:
    bool subscramble(string s1, string s2)
    {
        if(s1==s2)
            return true;
        string left1 = s1, left2 = s2, right1, right2;
        sort(left1.begin(), left1.end());
        sort(left2.begin(), left2.end());
        if(left1 != left2)
            return false;
        for(int i = 1; i<s1.length(); ++i)
        {
            left1 = s1.substr(0, i);
            left2 = s1.substr(i);
            right1 = s2.substr(0, i);
            right2 = s2.substr(i);
            if(subscramble(left1, right1) && subscramble(left2, right2))
                return true;
            left1 = s1.substr(0, s1.length()-i);
            left2 = s1.substr(s1.length()-i);
            if(subscramble(left1, right2) && subscramble(left2, right1))
                return true;
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        return subscramble(s1, s2);
    }
};
