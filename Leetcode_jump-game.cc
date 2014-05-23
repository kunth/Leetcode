class Solution {
public:
    bool canJump(int A[], int n) {
        if(n)
        {
        int maxlen = A[0];
        for(int i = 0; i < n && i<=maxlen; ++i)
        {
            if(i+A[i]>maxlen)
            {
                maxlen = i+A[i];
            }
        }
        return maxlen>=n-1 ? true : false;
        }
        return true;
    }
};
