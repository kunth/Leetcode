//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        map<int, int>dm;
        for(int i = 0; i < n; ++i)
        {
            if(dm[A[i]]==0)
            {
                dm[A[i]] = 1;
            }
            else if(dm[A[i]]==1)
            {
                dm[A[i]] = 2;
            }
            else
            {
                for(int j = i; j < n-1; ++j)
                {
                    A[j] = A[j+1];
                }
                --i;
                --n;
            }
        }
        return n;
    }
};

//SECOND TRIAL, in place
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2)
            return n;
        int len = 1;
        bool flag = true;
        for(int i = 1; i<n; ++i)
        {
            if(A[i]!=A[len-1])
            {
                A[len++] = A[i];
                flag = true;
            }
            else if(flag)
            {
                A[len++] = A[i];
                flag = false;
            }
        }
        return len;
    }
};
