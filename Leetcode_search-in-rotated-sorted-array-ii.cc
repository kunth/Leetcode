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

//SECOND TRIAL
class Solution {
private:
    bool rotatedSearch(int A[], int left, int right, int target)
    {
        if(!A || left > right)
            return false;
        int mid = (left+right)/2;
        if(A[mid]==target || A[left]==target || A[right]==target)
            return true;
        if(A[left]<A[mid])
        {
            if(target>A[left] && target<A[mid] && rotatedSearch(A, left+1, mid-1, target))
                return true;
            return rotatedSearch(A, mid+1, right-1, target);
        }
        else if(A[left]>A[mid])
        {
            if(target>A[mid] && target<A[right] && rotatedSearch(A, mid+1, right-1, target))
                return true;
            return rotatedSearch(A, left+1, mid-1, target);
        }
        else
        {
            if(rotatedSearch(A, left+1, mid-1, target))
                return true;
            return rotatedSearch(A, mid+1, right-1, target);
        }
    }
public:
    bool search(int A[], int n, int target) {
        return rotatedSearch(A, 0, n-1, target);
    }
};
