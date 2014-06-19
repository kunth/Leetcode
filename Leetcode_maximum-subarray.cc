class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxsum = A[0], sum=0;
        for(int i = 0; i < n; ++i)
        {
            sum += A[i];
            maxsum = maxsum >= sum ? maxsum : sum;
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return maxsum;
    }
};

//SECOND TRIAL
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans = A[0], sum = 0;
        for(int i = 0; i<n; ++i)
        {
            sum += A[i];
            ans = max(ans, sum);
            if(sum<0)
                sum = 0;
        }
        return ans;
    }
};
