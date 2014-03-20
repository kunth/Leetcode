//http://oj.leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(int A[], int n) {
        sort(A, A+n);
        for(int i = 0; i < n; ++i)
        {
            if(i==0)
            {
                if(A[i] != A[i+1])
                {
                    return A[i];
                }
            }
            else if(i==n-1)
            {
                if(A[i] != A[i-1])
                {
                    return A[i];
                }
            }
            else if(A[i] != A[i-1] && A[i] != A[i+1])
            {
                return A[i];
            }
        }
    }
};
