class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int begin = 0, diff = 0;
        std::sort(A, A+n);
        for(int i = 0; i < n; ++i)
        {
            if(A[i]==elem)
            {
                begin = i;
                ++diff;
                while(++i < n && A[i]==elem)
                {
                    ++diff;
                }
                if(i<n)
                {
                    for(;i<n;++i)
                    {
                        A[i-diff]=A[i];
                    }
                }
            }
        }
        return n-diff;
    }
};
