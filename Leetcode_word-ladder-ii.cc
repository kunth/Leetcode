class Solution {
private:
    unordered_map<string, vector<string>>findlast;
    vector<vector<string>>ans;
public:
    void findnext(string cur, unordered_set<string>&dict, unordered_set<string>&nxts)
    {
        string nxt;
        for(int i = 0; i<cur.length(); ++i)
        {
            for(char ch = 'a'; ch<='z'; ++ch)
            {
                if(ch!=cur[i])
                {
                   nxt = cur;
                   nxt[i] = ch;
                   if(dict.find(nxt)!=dict.end())
                   {
                       findlast[nxt].push_back(cur);
                       nxts.insert(nxt);
                   }
                }
            }
        }
    }
    void bulitpath(vector<string>&vec, const string& start, const string& end)
    {
        if(end==start)
        {
            vector<string>v(vec.rbegin(), vec.rend());
            ans.push_back(v);
        }
    
        for(int i = 0; i<findlast[end].size(); ++i)
        {
            vec.push_back(findlast[end][i]);
            bulitpath(vec, start, findlast[end][i]);
            vec.pop_back();
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        ans.clear();
        unordered_set<string>curs, nxts;
        curs.insert(start);
        dict.insert(start);
        dict.insert(end);
        vector<string>vec;
        vec.push_back(end);
        while(!curs.empty())
        {
            for(auto it = curs.begin(); it != curs.end(); ++it)
                dict.erase(*it);
            for(auto it = curs.begin(); it != curs.end(); ++it)
                findnext(*it, dict, nxts);

            if(nxts.find(end)!=dict.end())
            {
                bulitpath(vec, start, end);
                return ans;
            }

            curs = nxts;
            nxts.clear();
        }
        return ans;
    }
};
