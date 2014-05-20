class Solution {
public:
    string minWindow(string S, string T) {
        if(S.empty() || T.empty() || S.length() < T.length())
            return "";
        const int CHAR_SIZE = 256;
        int appeared[CHAR_SIZE], expected[CHAR_SIZE], start = 0, matched = 0, min_start = 0, minlen = INT_MAX;
        memset(appeared, 0, sizeof(appeared));
        memset(expected, 0, sizeof(appeared));
        for(int i = 0; i<T.length(); ++i)
            ++expected[T[i]];
        for(int i = 0; i<S.length(); ++i)
        {
            if(expected[S[i]])
            {
                if(appeared[S[i]]<expected[S[i]])
                {
                    ++matched;
                }
                ++appeared[S[i]];
                if(matched == T.length())
                {
                    while(!expected[S[start]] || appeared[S[start]] > expected[S[start]])
                    {
                        if(appeared[S[start]] > expected[S[start]])
                        {
                            --appeared[S[start]];
                        }
                        ++start;
                    }
                    if(minlen > i-start+1)
                    {
                        min_start = start;
                        minlen = i - start + 1;
                    }
                }
            }
        }
        if(matched<T.length())
            return "";
        return S.substr(min_start, minlen);
    }
};
