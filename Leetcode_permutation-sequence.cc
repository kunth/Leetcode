class Solution {
public:
    int factorial(int num)
    {
        int ans = 1;
        while(num>=2)
            ans *= num--;
        return ans;
    }
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int>vec(n, 0);
        for(int i = 0; i<n; ++i)
            vec[i] = i+1;
        int idx = 0, fa = 0;
        while(!vec.empty())
        {
            fa = factorial(n-1);
            if(k)
                idx = (k-1) / fa;
            else
                idx = n-1;
            ans += vec[idx] + '0';
            vec.erase(vec.begin()+idx);
            k = k % fa;
            --n;
        }
        return ans;
    }
};
