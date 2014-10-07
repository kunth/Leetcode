class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <=1)
        {
            return s;
        }
        string str;
        for(int i = 0; i < nRows; ++i)
        {
            for(int j = 0; i+j*(2*nRows-2)<s.length(); ++j)
            {
                str+=s[i+j*(2*nRows-2)];
                if(i > 0 && i < nRows-1)
                {
                    if(i+(j+1)*(2*nRows-2)-2*i<s.length())
                    {
                        str+=s[i+(j+1)*(2*nRows-2)-2*i];
                    }
                }
            }
        }
        return str;
    }
};

//Second trial
class Solution {
public:
    string convert(string s, int nRows) {
        string ans;
        int len = s.length();
        if(len<=nRows || nRows==1)
            return s;
        int j;
        for(int i = 0; i<nRows; ++i) {
            j = i;
            while(j<len) {
                ans += s[j];
                if(!i || i==nRows-1)
                    j += 2*(nRows-1);
                else {
                    j += 2*(nRows-1)-2*i;
                    if(j<len)
                        ans += s[j];
                    j += 2*i;
                }
            }
        }
        return ans;
    }
};
