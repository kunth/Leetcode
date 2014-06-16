class Solution {
public:
  
    int bsearch(int A[], int left, int right, int target)
    {
        if(left>right)
        {
            return -1;
        }
        int mid = (left+right)/2;
        if(A[mid]==target)
        {
            return mid;
        }
        else if(A[mid]<target)
        {
            left = mid+1;
            return bsearch(A, left, right, target);
        }
        else
        {
            right = mid-1;
            return bsearch(A, left, right, target);
        }
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> vec;
        int ret = bsearch(A, 0, n-1, target);
        if(ret==-1)
        {
            vec.push_back(-1);
            vec.push_back(-1);
            return vec;
        }
        int low = ret, high = ret;
        while(low-1>=0 && A[low-1]==target)
            --low;
        while(high+1<n && A[high+1]==target)
            ++high;
        vec.push_back(low);
        vec.push_back(high);
        return vec;
    }
};

//SECOND TRIAL
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int>ans;
        int left = 0, right = n-1, mid;
        while(left <= right)
        {
            mid = (left+right)/2;
            if(A[mid]<target)
                left = mid+1;
            else if(A[mid]>target)
                right = mid-1;
            else
            {
                left = mid - 1;
                right = mid + 1;
                while(left>=0 && A[left]==target)
                    --left;
                while(right < n && A[right]==target)
                    ++right;
                ans.push_back(left+1);
                ans.push_back(right-1);
                return ans;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};

