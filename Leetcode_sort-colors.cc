class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0, right = n-1;
        for(int i = 0; i < n && left<right;)
        {
            if(A[i]==0)
            {
                if(i>left)
                {
                    A[i]=A[left];
                    A[left++] = 0;
                }
                else
                    ++i;
            }
            else if(A[i]==2)
            {
                if(i<right)
                {
                    A[i]=A[right];
                    A[right--]=2;
                }
                else
                    ++i;
            }
            else
                ++i;
        }
    }
};

//second trial
class Solution {
public:
    void sortColors(int A[], int n) {
        int i = 0, j = n-1, k=0;
        while(k>=i && k<=j)
        {
            if(A[k]==0)
                swap(A[i++], A[k]);
            else if(A[k]==2)
                swap(A[j--], A[k]);
            else
                ++k;
            if(i>k)
                k = i;
        }
    }
};
