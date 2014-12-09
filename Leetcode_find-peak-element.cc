//Solution 1: O(n) time complexity
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

//Solution 2: O(logn) time complexity
class Solution {
private:
    int findSubPeak(const vector<int>& vec, int left, int right) {
        int sz = vec.size();
        if(sz==1) {
            if((left==INT_MIN || left < vec[0]) && (right==INT_MIN || right < vec[0]))
                return 0;
            else
                return -1;
        } else if(sz==2) {
            if((left==INT_MIN || left < vec[0]) && vec[0] > vec[1])
                return 0;
            else if(vec[0] < vec[1] && (right==INT_MIN || vec[1] > right))
                return 1;
            else
                return -1;
        }
        vector<int>lvec(vec.begin(), vec.begin()+sz/2);
        vector<int>rvec(vec.begin()+sz/2+1, vec.end());
        int x = findSubPeak(lvec, left, vec[sz/2]);
        if(x != -1)
            return x;
        if(vec[sz/2] > vec[sz/2-1] && vec[sz/2] > vec[sz/2+1])
            return sz/2;
        x = findSubPeak(rvec, vec[sz/2], right);
        if(x != -1)
            return x+sz/2+1;
        return -1;
    }
public:
    int findPeakElement(const vector<int> &num) {
        return findSubPeak(num, INT_MIN, INT_MIN);
    }
};
