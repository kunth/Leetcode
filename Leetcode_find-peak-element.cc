class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int sz = num.size();
        if(sz==1)
            return 0;
        
        for(int i = 1; i<sz-1; ++i)
            if(num[i] > num[i-1] && num[i] > num[i+1])
                return i;
        
        if(num[0]>num[1])
            return 0;
        else if(num[sz-1]>num[sz-2])
            return sz-1;
    }
};
