//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int diff = 0;
        for(int i = 0; i < n-1; ++i)
        {
            if(A[i]==A[i+1])
            {
                while(i < n-1 && A[i]==A[i+1])
                {
                    ++diff;
                    ++i;
                }
            }
            A[i-diff] = A[i];
        }
        A[n-1-diff] = A[n-1];
        return n-diff;
    }
};

//SECOND TRIAL
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1)
            return n;
        int cnt = 1;
        for(int i = 1; i<n; ++i)
        {
            if(A[i]!=A[cnt-1])
            {
                A[cnt] = A[i];
                ++cnt;
            }
        }
        return cnt;
    }
};
