//http://oj.leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = A[0];
        for(int i = 1; i < n; ++i)
        {
            ret ^= A[i];
        }
        return ret;    
    }
};
