class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int front = 0, rear = n-1, mid;
        while(front<=rear)
        {
            mid = (front+rear)/2;
            if(A[mid]==target)
            {
                return mid;
            }
            else if(A[mid] < target)
            {
                front = mid+1;
            }
            else
            {
                rear = mid-1;
            }      
        }
        if(mid > rear)
        {
            return mid;
        }
        return mid+1;
    }
};

//SECOND TRIAL
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(!A || !n)
            return 0;
        int left = 0, right = n-1, mid;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(target == A[mid])
                return mid;
            else if(target < A[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
    }
};
