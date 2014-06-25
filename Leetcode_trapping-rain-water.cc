class Solution {
public:
    int trap(int A[], int n) {
        if(n<3)
            return 0;
        int ans = 0, maxheight = A[0], idx = 0;
        for(int i = 1; i<n; ++i)
        {
            if(A[i]>maxheight)
            {
                maxheight = A[i];
                idx = i;
            }
        }
        int left = idx-1, right = idx+1, lidx = 0, ridx = n-1;
        if(left>=1)
        {
            int maxleft = A[left];
            lidx = left;
            while(left>=0)
            {
                if(A[left]>maxleft)
                {
                    maxleft = A[left];
                    lidx = left;
                }
                --left;
            }
            for(int i = lidx+1; i<idx; ++i)
                ans += (maxleft-A[i]);
            ans += trap(A, lidx+1);
        }
        if(right<=n-2)
        {
            int maxright = A[right];
            ridx = right;
            while(right<n)
            {
                if(A[right]>maxright)
                {
                    maxright = A[right];
                    ridx = right;
                }
                ++right;
            }
            for(int i = idx+1; i<ridx; ++i)
                ans += (maxright-A[i]);
            ans += trap(A+ridx, n-ridx);
        }
        return ans;
    }
};
