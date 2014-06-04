//SECOND TRIAL, 12ms
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(!A)
            return 0;
        int i = 0;
        while(i < n)
        {
            if(A[i]==elem)
                swap(A[i], A[--n]);
            else
                ++i;
        }
        return n;
    }
};

//FIRST TRIAL
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
