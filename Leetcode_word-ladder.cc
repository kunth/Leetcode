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

//Second trial, almost the same
//There is no boundary conditions e.g. start == end
class Solution {
private:
    string end;
    unordered_map<string, bool>dm;
public:
    int bfs(queue<string>&strq, queue<int>&depthq, unordered_set<string>&dict)
    {
        string cur, str;
        int depth;
        while(!strq.empty())
        {
            cur = strq.front();
            strq.pop();
            depth = depthq.front();
            depthq.pop();
            for(int i = 0; i<cur.length(); ++i)
            {
                for(char ch = 'a'; ch<='z'; ++ch)
                {
                    if(ch != cur[i])
                    {
                        str = cur;
                        str[i] = ch;
                        if(str==end)
                            return 1+depth;
                        if(dict.find(str)!=dict.end() && !dm[str])
                        {
                            dm[str] = true;
                            strq.push(str);
                            depthq.push(1+depth);
                        }
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string>strq;
        queue<int>depthq;
        strq.push(start);
        depthq.push(1);
        this->end = end;
        return bfs(strq, depthq, dict);
    }
};
