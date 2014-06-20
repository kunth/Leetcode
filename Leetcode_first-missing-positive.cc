class Solution {
public:
    bool bs[1000000];
    int firstMissingPositive(int A[], int n) {
        memset(bs, 0, sizeof(bs));
        for(int i = 0; i < n; ++i)
        {
            if(A[i]>0)
            {
                bs[A[i]]=true;;
            }
        }
        int j = 1;
        while(j < 1000000 && bs[j])
        {
            ++j;
        }
        return j;
    }
};

//SECOND TRIAL, O(N) running time with constant space
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int k = 0;
        while(k<n)
        {
            if(A[k]>0 && A[k]<=n)
            {
                if(A[k]<=k+1)
                    A[A[k]-1] = A[k++];
                else if(A[A[k]-1]<=0 || A[A[k]-1]>n)
                    A[A[k]-1] = A[k++];
                else if(A[A[k]-1]!=A[k])
                    swap(A[k], A[A[k]-1]);
                else
                    ++k;
            }
            else
                ++k;
        }
        for(int i = 0; i<n; ++i)
            if(A[i]!=i+1)
                return i+1;
        return n+1;
    }
};
