class Solution {
public:
    int jump(int A[], int n) {
        if(n==1)
            return 0;
        int cur = 0, nxt = 0, farthest = 0, ans = 0;
        while(cur <= farthest)
        {
            ++ans;
            nxt = farthest+1;
            for(int i = cur; i<nxt; ++i)
            {
                if(i+A[i]>farthest)
                {
                    farthest = i+A[i];
                    if(farthest>=n-1)
                        return ans;
                }
            }
            cur = nxt;
        }
    }
};

//SECOND TRIAL
class Solution {
public:
    int jump(int A[], int n) {
        if(n==1)
            return 0;
        if(A[0]>=n-1)
            return 1;
        int ans = 1, begin = 0, end = A[0], step = 0;
        while(1)
        {
            while(begin<=end)
            {
                step = max(step, begin+A[begin]);
                ++begin;
            }
            if(step>=n-1)
                return 1+ans;
            begin = end;
            end = step;
            ++ans;
        }
    }
};
