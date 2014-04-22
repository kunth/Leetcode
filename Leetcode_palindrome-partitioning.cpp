class Solution {
public:
	void dfs(vector<vector<string>>&ans, vector<string>&vec, string tmpstr, string s)
	{
		if(s.empty())
		{
			if(tmpstr.empty())
			    ans.push_back(vec);
			return;
		}
		tmpstr += s.substr(0, 1);
		if(tmpstr.length()==1)
		{
			vec.push_back(s.substr(0, 1));
			dfs(ans, vec, "", s.substr(1));
			vec.pop_back();
			dfs(ans, vec, tmpstr, s.substr(1));
		}
		else
		{
			string str = tmpstr;
			reverse(tmpstr.begin(), tmpstr.end());
			if(str==tmpstr)
			{
				vec.push_back(tmpstr);
				dfs(ans, vec, "", s.substr(1));
				vec.pop_back();
			}
			dfs(ans, vec, str, s.substr(1));
		}
	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>>ans;
		if(s.empty())
			return ans;
		vector<string>vec;
		dfs(ans, vec, "", s);
		return ans;
	}
};
