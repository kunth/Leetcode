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
