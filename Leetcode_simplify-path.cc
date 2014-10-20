class Solution {
public:
    string simplifyPath(string path) {
        vector<string>vec;
        string ans, dir;
        for(int i = 0; i < path.length(); )
        {
            int j = i;
            while(j < path.length() && path[j]!='/')
                ++j;
            dir = path.substr(i, j-i);
            if(!dir.empty())
            {
                if(dir=="..")
                {
                    if(!vec.empty())
                        vec.pop_back();
                }
                else if(dir!=".")
                    vec.push_back(dir);
            }
            i = j + 1;
        }
        if(vec.empty())
            return "/";
        else
        {
            
            for(int i = 0; i<vec.size(); ++i)
            {
                ans += '/';
                ans += vec[i];
            }
        }
        return ans;
    }
};

//Another Solution
class Solution {
private:
    vector<string> split(string str){
        vector<string>ans;
        int begin = 0;
        for(int i = 0; i<str.length(); ++i) {
            if(str[i]=='/') {
                if(i>begin)
                    ans.push_back(str.substr(begin, i-begin));
                begin = i+1;
            }
        }
        if(begin<str.length())
            ans.push_back(str.substr(begin));
        return ans;
    }
public:
    string simplifyPath(string path) {
        if(path.empty())
            return path;
        stack<string>st, rst;
        vector<string>vec = split(path);
        for(int i = 0; i<vec.size(); ++i) {
            if(vec[i]=="..") {
                if(!st.empty())
                    st.pop();
            } else if(vec[i]==".") {
                continue;
            } else {
                st.push(vec[i]);
            }
        }
        string ans;
        if(st.empty()){
            ans = "/";
        } else {
            while(!st.empty()) {
                rst.push(st.top());
                st.pop();
            }
            while(!rst.empty()) {
                ans += "/";
                ans += rst.top();
                rst.pop();
            }
        }
        return ans;
    }
};
