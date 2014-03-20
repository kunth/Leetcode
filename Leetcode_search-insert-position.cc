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
