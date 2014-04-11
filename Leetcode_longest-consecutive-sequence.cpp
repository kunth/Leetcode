class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty())
            return 0;
        map<int, bool>dm;
        for(int i = 0; i<num.size(); ++i)
            dm[num[i]] = true;
        int maxlen = 1, len = 1;
        auto it = dm.begin(), next_it = dm.begin();
        ++next_it;
        while(next_it != dm.end())
        {
            if(next_it->first == it->first + 1)
            {
                ++len;
                maxlen = len > maxlen ? len : maxlen;
            }
            else
                len = 1;
            ++it;
            ++next_it;
        }
        return maxlen;
    }
};
