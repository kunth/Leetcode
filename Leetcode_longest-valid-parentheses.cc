class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        vector<bool>flag(s.length(), false);
        for(int i = 0; i<s.length(); ++i)
        {
            if(s[i]==')')
            {
                int j = i-1;
                while(j>=0 && flag[j])
                    --j;
                if(j>=0 && s[j]=='(')
                {
                    flag[i] = flag[j] = true;
                }
            }
        }
        int ans = 0, len = 0;
        for(int i = 0; i<flag.size(); ++i)
        {
            if(flag[i])
            {
                while(i<flag.size() && flag[i])
                {
                    ++len;
                    ++i;
                }
                ans = max(ans, len);
                len = 0;
            }
        }
        return ans;
    }
};

//Solution Two, O(N) time
//Use vector to store the current '(' which need to be matched, instead of searching backward
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        stack<char>st;
        vector<bool>flag(s.length(), false);
        vector<int>vec;
        int ans = 0, cur = 0;
        for(int i = 0; i<s.length(); ++i) {
            if(s[i]=='(') {
                st.push(s[i]);
                vec.push_back(i);
            } else {
                if(!st.empty()) {
                    if(st.top()=='(') {
                        st.pop();
                        flag[i] = flag[vec.back()] = true;
                        vec.pop_back();
                    }
                }
            }
        }
        for(int i = 0; i<s.length(); ++i) {
            if(flag[i]) {
                ++cur;
            } else {
                ans = max(ans, cur);
                cur = 0;
            }
        }
        ans = max(ans, cur);
        return ans;
    }
};
