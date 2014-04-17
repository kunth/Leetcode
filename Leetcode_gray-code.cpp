class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        n = 1 << n;
        for(int i = 0; i<n; ++i)
        {
            ans.push_back((i>>1)^i);
        }
        return ans;
    }
};
