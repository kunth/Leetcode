class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string>ans, vec;
        int i = 0, len = 0, cnt = 0, space = 0, carry = 0;
        while(i < words.size())
        {
            string str;
            while(i < words.size() && len + cnt + words[i].length()<= L)
            {
                len += words[i].length();
                ++cnt;
                vec.push_back(words[i++]);
            }
            if(cnt == 1)
            {
                str += vec[0];
                while(str.length()<L)
                {
                    str += ' ';
                }
            }
            else
            {
                if(i>=words.size())
                {
                     for(int j = 0; j<cnt; ++j)
                     {
                          str += vec[j];
                          if(j!=cnt-1)
                          {
                               str += ' ';
                          }
                     }
                     while(str.length()<L)
                          str += ' ';
                     ans.push_back(str);
                     break;
                }
                space = (L-len)/(cnt-1);
                carry = (L-len)%(cnt-1);
                for(int j = 0; j<cnt; ++j)
                {
                    str += vec[j];
                    if(j < cnt-1)
                    {
                        for(int k = 0; k<space; ++k)
                        {
                            str += ' ';
                        }
                    }
                    if(carry)
                    {
                        str += ' ';
                        --carry;
                    }
                }
            }
            ans.push_back(str);
            len = cnt = carry = 0;
               vec.clear();
        }
        return ans;
    }
};
