//http://oj.leetcode.com/submissions/detail/4866109/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pa = 0, pb = 0, len=m+n;
        for(; pa<m && pb<n; )
        {
            if(A[pa]>B[pb])
            {
                for(int i = m; i>pa; --i)
                {
                    A[i]=A[i-1];
                }
                A[pa] = B[pb];
                ++m;
                ++pb;
            }
            ++pa;
        }
        //if(m < len)
        //{
            while(pb<n)
            {
                A[m++] = B[pb++];
            }
        //}
    }
};
