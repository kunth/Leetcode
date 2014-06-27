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

//SOLUTION TWO, which is better.
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(!n)
            return;
        if(!m)
        {
            for(int i = 0; i<n; ++i)
                A[i] = B[i];
            return;
        }
        int i = m-1, j = n-1;
        while(i>=0 && j>=0)
        {
            if(A[i]>=B[j])
                A[i+j+1] = A[i--];
            else
                A[i+j+1] = B[j--];
        }
        if(j<0)
            return;
        for(; j>=0; --j)
            A[j] = B[j];
    }
};
