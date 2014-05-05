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
