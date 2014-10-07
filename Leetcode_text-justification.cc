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


//Second trial
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string>ans;
        if(words.empty())
            return ans;
        int i = 0, cnt = 0, j = 0, sz = 0, left = 0, quotient = 0;
        while(i<words.size()) {
            cnt = words[i].length();
            j = i+1;
            sz = 1;
            string line = words[i];
            while(j<words.size() && cnt + sz + words[j].length()<=L) {
                cnt += words[j].length();
                ++j;
                ++sz;
            }
            if(sz==1) {
                line.append(L-line.length(), ' ');
            } else {
                if(j>=words.size()) {
                    for(int k = 0; k<sz; ++k) {
                        if(k)
                            line+=words[i+k];
                        line+=' ';
                    }
                    line.append(L-line.length(), ' ');
                    ans.push_back(line);
                    break;
                }
                quotient = (L-cnt)/(sz-1);
                left = (L-cnt)%(sz-1);
                for(int k = 0; k<sz; ++k) {
                    if(k)
                        line += words[i+k];
                    if(k<sz-1)
                        line.append(quotient, ' ');
                    if(left) {
                        line += ' ';
                        --left;
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};
