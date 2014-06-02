class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); ++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                    continue;
                }
                return false;
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                {
                    st.pop();
                    continue;
                }
                return false;
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                {
                    st.pop();
                    continue;
                }
                return false;
            }
        }
        return st.empty() ? true : false;
    }
};

//SECOND TRIAL
class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char>st;
        for(int i = 0; i<s.length(); ++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
