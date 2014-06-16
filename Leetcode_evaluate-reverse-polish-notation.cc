//http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int a, b, val;
        stack<int> st;
        for(int i = 0; i < tokens.size(); ++i)
        {
            string str = tokens[i];
            if(!str.compare("+") || !str.compare("-") || !str.compare("*") || !str.compare("/"))
            {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                switch(*(str.c_str()))
                {
                    case '+':
                    val = a+b;
                    break;
                    case '-':
                    val = a-b;
                    break;
                    case '*':
                    val = a * b;
                    break;
                    case '/':
                    val = a / b;
                    break;
                    default:
                    break;
                }
                st.push(val);
            }
            else
            {
                int num;
                stringstream ss;
                ss << str;
                ss >> num;
                st.push(num);
            }
        }
        return st.top();
    }
};

//SECOND TRIAL, almost the same
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty())
            return 0;
        stack<int>st;
        stringstream ss;
        int x, y;
        string str;
        for(int i = 0; i<tokens.size(); ++i)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                y = st.top();
                st.pop();
                x = st.top();
                st.pop();
                if(tokens[i]=="+")
                    x += y;
                else if(tokens[i]=="-")
                    x -= y;
                else if(tokens[i]=="*")
                    x *= y;
                else
                    x /= y;
                    
                st.push(x);
            }
            else
            {
                str = tokens[i];
                ss << str;
                ss >> x;
                st.push(x);
                ss.str("");
                ss.clear();
            }
        }
        return st.top();
    }
};
