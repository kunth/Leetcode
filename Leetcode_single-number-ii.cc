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

//SECOND TRIAL
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = 0, bit_check = 0, bit_cnt = 0;
        for(int i = 0; i<=31; ++i)
        {
            bit_check = 1<<i;
            bit_cnt = 0;
            for(int j = 0; j<n; ++j)
                if(A[j] & bit_check)
                    ++bit_cnt;
            if(bit_cnt % 3)
                ans |= bit_check;
        }
        return ans;
    }
};
