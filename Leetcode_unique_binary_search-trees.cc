class Solution {
public:
    int numTrees(int n) {
        if(n<=2)
            return n;
        int res[1000];
        res[0]=0;
        res[1]=1;
        res[2]=2;
        for(int i=3; i<=n; ++i)
        {
            res[i] = 2*res[i-1];
            for(int j = 1; j < i-1; ++j)
                res[i] += res[j]*res[i-j-1];
        }
        return res[n];
    }
};
