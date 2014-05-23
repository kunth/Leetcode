class Solution {
public:
    bool bs[1000000];
    int firstMissingPositive(int A[], int n) {
        memset(bs, 0, sizeof(bs));
        for(int i = 0; i < n; ++i)
        {
            if(A[i]>0)
            {
                bs[A[i]]=true;;
            }
        }
        int j = 1;
        while(j < 1000000 && bs[j])
        {
            ++j;
        }
        return j;
    }
};
