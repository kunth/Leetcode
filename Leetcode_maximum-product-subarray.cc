class Solution {
private:
    int maxSubProduct(int A[], int n) {
        if(n<=0)
            return n;
        else if(n==1)
            return A[0];
        vector<int>vec;
        for(int i = 0; i<n; ++i)
            if(A[i]<0)
                vec.push_back(i);
        int ans = 1, tag = 0, tmp = 1;
        if(vec.size() & 0x01) { //odd
            if(vec.size()==1) {
                for(int i = 0; i<vec[0]; ++i) {
                    ans *= A[i];
                }
                for(int i = vec[0]+1; i<n; ++i) {
                    tmp *= A[i];
                }
                if(tmp != 1)
                    ans = max(ans, tmp);
            }else {
                for(int i = 0; i<=vec[vec.size()-1]-1; ++i)
                    ans *= A[i];
                for(int i = vec[0]+1; i<n; ++i)
                    tmp *= A[i];
                ans = max(ans, tmp);
            }
        }else { //even
            for(int i = 0; i<n; ++i)
                ans *= A[i];
        }
        return ans;
    }
public:
    int maxProduct(int A[], int n) {
        int begin = 0, ans = A[0];
        int i = 0;
        while(i<=n) {
            if(i==n) {
                ans = max(ans, maxSubProduct(A+begin, i-begin));
                break;
            }
            if(!A[i] && i<n) {
                ans = max(0, max(ans, maxSubProduct(A+begin, i-begin)));
                begin = ++i;
            } else
                ++i;
        }
        return ans;
    }
};
