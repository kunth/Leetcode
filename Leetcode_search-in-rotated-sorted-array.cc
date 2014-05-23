class Solution {
public:
    int bs(int A[], int left, int right, int target)
    {
        if(left>right)
            return -1;
        int mid = (left+right)/2;
        if(A[mid]<target)
        {
            left=mid+1;
            return bs(A, left, right, target);
        }
        else if(A[mid]>target)
        {
            right = mid-1;
            return bs(A, left, right, target);
        }
        return mid;
    }

    int search(int A[], int n, int target) {
        int i = 0;
        while(i+1<n && A[i]<A[i+1])
        {
            ++i;
        }
        if(A[0]<=target && i< n && target<=A[i])
        {
            return bs(A, 0, i, target);
        }
        else if(i+1 < n && A[i+1]<=target && target<=A[n-1])
        {
            return bs(A, i+1, n-1, target);
        }
        return -1;
    }
};
