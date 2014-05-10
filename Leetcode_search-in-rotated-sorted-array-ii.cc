class Solution {
public:
    bool binary_search(int A[], int n, int target)
    {
        int left = 0, right = n-1, mid = 0;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(target < A[mid])
                right = mid-1;
            else if(target > A[mid])
                left = mid+1;
            else
                return true;
        }
        return false;
    }
    bool search(int A[], int n, int target) {
        if(!n)
            return false;
        if(n==1)
            return A[0] == target;
        int pos = 0;
        while(pos<n-1 && A[pos]<=A[pos+1])
            ++pos;
        if(target > A[0])
            return binary_search(A, pos+1, target);
        else if(target < A[0])
            return binary_search(A+pos+1, n-pos-1, target);
        else
            return true;
    }
};
