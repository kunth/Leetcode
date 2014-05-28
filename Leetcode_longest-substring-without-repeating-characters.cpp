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


//second trial
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        unordered_map<char, int>mp;
        unordered_map<char, int>::iterator it;
        int i = 0, mlen = 0;
        for(int k = 0; k<s.length(); ++k)
        {
            it = mp.find(s[k]);
            if(it == mp.end())
                mp[s[k]]=k;
            else
            {
                while(s[i]!=s[k])
                {
                    it = mp.find(s[i]);
                    mp.erase(it);
                    ++i;
                }
                ++i;
            }
            mlen = max(mlen, k-i+1);
        }
        return mlen;
    }
};
