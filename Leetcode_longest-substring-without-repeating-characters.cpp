class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, len = 0;
        deque<char> q;
        map<char, bool> resmap;
        for(int i = 0; i < s.length(); ++i)
        {
            auto it = resmap.find(s[i]);
            if(it == resmap.end())
            {
                ++len;
                q.push_back(s[i]);
                maxlen = maxlen > len ? maxlen : len;
                resmap.insert(pair<char,bool>(s[i], true));
            }
            else
            {
                while(!q.empty() && q.front() != s[i])
                {
                    auto deleteIt = resmap.find(q.front());
                    resmap.erase(deleteIt);
                    q.pop_front();
                }
                q.pop_front();
                q.push_back(s[i]);
                len = q.size();
            }
        }
        return maxlen;
    }
};
