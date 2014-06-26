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

//SECOND TRIAL, although unordered_map is supposed to be O(n), but it is slower than map in this case
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty())
            return 0;
        unordered_map<int, bool>hashmap;
        for(int i = 0; i<num.size(); ++i)
            hashmap[num[i]] = true;
        int ans = 0, cnt = 0, val = 0;
        while(!hashmap.empty())
        {
            auto it = hashmap.begin();
            val = it->first;
            cnt = 0;
            auto eraseIt = hashmap.find(++val);
            while(eraseIt!=hashmap.end())
            {
                hashmap.erase(eraseIt);
                eraseIt = hashmap.find(++val);
                ++cnt;
            }
            val = it->first;
            eraseIt = hashmap.find(--val);
            while(eraseIt!=hashmap.end())
            {
                hashmap.erase(eraseIt);
                eraseIt = hashmap.find(--val);
                ++cnt;
            }
            hashmap.erase(hashmap.begin());
            ans = max(ans, 1+cnt);
        }
        return ans;
    }
};
