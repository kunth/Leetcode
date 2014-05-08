class Solution {
public:
    //find kth smallest number, which applies to any kth number
    double find_kth_num(int A[], int m, int B[], int n, int k)
    {
        if(m > n)
            return find_kth_num(B, n, A, m, k);
        if(m==0)
            return B[k-1];
        if(k == 1)
            return min(A[0], B[0]);
        int idx_a = min(m, k/2);
        int idx_b = k - idx_a;
        if(A[idx_a-1] < B[idx_b-1])
            return find_kth_num(A+idx_a, m-idx_a, B, n, k-idx_a);
        else if(A[idx_a-1] > B[idx_b-1])
            return find_kth_num(A, m, B+idx_b, n-idx_b, k-idx_b);
        else
        //these two parts together count to lenght k, just find the kth smallest number
            return A[idx_a-1];
        
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)&1)
            return (double)find_kth_num(A, m, B, n, (m+n)/2+1);
        else
            return 0.5 * (find_kth_num(A, m, B, n, (m+n)/2) + find_kth_num(A, m, B, n, (m+n)/2+1));
    }
};
