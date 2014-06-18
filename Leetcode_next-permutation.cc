class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.empty())
            return;
        int pos = num.size()-1;
        while(pos && num[pos]<=num[pos-1])
            --pos;
        if(!pos)
            sort(num.begin(), num.end());
        else
        {
            for(int i = num.size()-1; i>=pos; --i)
                if(num[i] > num[pos-1])
                {
                    swap(num[i], num[pos-1]);
                    break;
                }
            sort(num.begin()+pos, num.end());
        }
    }
};


//what's more, it can also abandon sorting at last. What's amazing is the code below is 20ms+ later than the upper one.
//I think there must be some optimizations in STL.
//coding two weeks later.

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.empty() || num.size()==1)
            return;
        int pos = num.size()-1;
        for(; pos>=1; --pos)
        {
            if(num[pos]>num[pos-1])
                break;
        }
        if(!pos)
        {
            for(int i=0, j=num.size()-1; i<j; ++i,--j)
                swap(num[i], num[j]);
        }
        else
        {
            for(int i = num.size()-1; i>=pos; --i)
            {
                if(num[i]>num[pos-1])
                {
                    swap(num[i], num[pos-1]);
                    break;
                }
            }
            for(int j = num.size()-1; j > pos; --j, ++pos)
                swap(num[j], num[pos]);
            return;
        }
    }
};

//Thrid trial
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.empty())
            return;
        int sz = num.size(), pos = 0;
        for(pos = sz-1; pos>=1; --pos)
        {
            if(num[pos]>num[pos-1])
                break;
        }
        if(!pos)
            reverse(num.begin(), num.end());
        else
        {
            for(int i = sz-1; i>=pos; --i)
            {
                if(num[i]>num[pos-1])
                {
                    swap(num[i], num[pos-1]);
                    break;
                }
            }
            reverse(num.begin()+pos, num.end());
        }
    }
};
