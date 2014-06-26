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

//
class Solution {
public:
    vector<int> grayCode(int n) {
        int sum = 1, num = 0;
        for(int i = 0; i<n; ++i)
            sum *= 2;
        vector<int>ans;
        for(int i = 0; i<sum; ++i)
        {
            num = i ^ i/2;
            ans.push_back(num);
        }
        return ans;
    }
};
