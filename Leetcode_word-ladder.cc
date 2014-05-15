class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(dict.empty() || start == end)
            return 0;
        queue<string>strq;
        queue<int>depq;
        strq.push(start);
        depq.push(1);
        string cur, nxt;
        int depth;
        unordered_set<string> visited;
        while(!strq.empty())
        {
            nxt = cur = strq.front();
            strq.pop();
            depth = depq.front();
            depq.pop();
            if(cur == end)
                return depth;
            for(int i = 0; i < cur.length(); ++i)
            {
                for(char ch = 'a'; ch<='z'; ++ch)
                {
                    if(ch!=cur[i])
                    {
                        nxt[i] = ch;
                        if(dict.find(nxt)!=dict.end() && visited.find(nxt)==visited.end())
                        {
                            visited.insert(nxt);
                            strq.push(nxt);
                            depq.push(depth+1);
                        }
                        nxt = cur;
                    }
                }
            }
        }
        return 0;
    }
};
