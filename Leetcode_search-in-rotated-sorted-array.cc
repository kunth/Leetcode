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

//SECOND TRIAL, O(logn) time
class Solution {
private:
    int findInRotatedArray(int A[], int left, int right, int target)
    {
        if(!A || left > right)
            return -1;
        if(left==right)
        {
            if(A[left]==target)
                return left;
            else
                return -1;
        }
        int mid = (left+right)/2;
        if(A[left]<A[mid])
        {
            if(A[left]<=target && target<=A[mid])
                return findInRotatedArray(A, left, mid, target);
            else
                return findInRotatedArray(A, mid+1, right, target);
        }
        else if(A[left]>A[mid])
        {
            if(target>=A[mid] && target<=A[right])
                return findInRotatedArray(A, mid, right, target);
            else
                return findInRotatedArray(A, left, mid-1, target);
        }
        else
        {
            if(A[mid]==A[right])
                return A[left]==target ? left : -1;

            int ans = findInRotatedArray(A, left, mid, target);
            if(ans<0)
                return findInRotatedArray(A, mid+1, right, target);
            return ans;
        }
    }
public:
    int search(int A[], int n, int target) {
        return findInRotatedArray(A, 0, n-1, target);
    }
};
