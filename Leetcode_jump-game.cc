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

//SECOND TRAIL
class Solution {
public:
    bool canJump(int A[], int n) {
        if(!A || n<0)
            return false;
        if(n==1)
            return true;
        int cur = 0, end = A[0], maxstep = 0;
        while(1)
        {
            while(cur<=end)
            {
                maxstep = max(maxstep, cur+A[cur]);
                ++cur;
                if(maxstep>=n-1)
                    return true;
            }
            if(maxstep<=end)
                return false;
            cur = end;
            end = maxstep;
            maxstep = 0;
        }
        return false;
    }
};
