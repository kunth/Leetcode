//http://oj.leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    void reverseWords(string &s) {
        string str;
        stack<string>st;
        int p1=0, p2=0, len=s.length();
        while(p2 < len)
        {
          while(p1<len && s[p1]==' ')
          {
              ++p1;
          }
          p2=p1;
          while(p2<len && s[p2]!=' ')
          {
              ++p2;
          }
          if(p2 <= len)
          {
              str = s.substr(p1,p2-p1);
              if(!str.empty())
              {
                  st.push(str);
                  ++p2;
                  p1 = p2;
              }
          }
        }
        str.clear();
        while(!st.empty())
        {
            str += st.top();
            if(st.size()>1)
            {
                str += " ";
            }
            st.pop();
        }
        s = str;
    }
};

//SECOND TRIAL
class Solution {
public:
	void reverseWords(string &s) {
		if(s.empty())
		    return;
		int p = 0, q = 0;
		stack<string>st;
		string str, news;
		while(q < s.length())
		{
		    while(q<s.length() && s[q]!=' ')
		        ++q;
		    str = s.substr(p, q-p);
		    if(!str.empty())
		        st.push(str);
		    p = ++q;
		}
		if(st.size()>1)
		{
		    while(!st.empty())
		    {
		        if(!news.empty())
		            news+=" ";
		        news+=st.top();
		        st.pop();
		    }
		    s = news;
		}
		else if(st.size()==1)
		    s = st.top();
		else
		    s = "";
	}
};
