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

//SECOND TRIAL, check the "catalan number"
class Solution {
public:
    int numTrees(int n) {
        int arr[100]={0};
        arr[0] = arr[1] = 1;
        if(n<=1)
            return arr[n];
        for(int i = 2; i<=n; ++i)
        {
            for(int j = 0; 2*j<i; ++j)
                arr[i] += 2*(arr[j] * arr[i-j-1]);
            if(i%2)
                arr[i] -= arr[i>>1] * arr[i>>1];
        }
        return arr[n];
    }
};
