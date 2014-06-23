class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        if(!rowIndex)
        {
            res.push_back(1);
            return res;
        }
        else if(rowIndex==1)
        {
            res.push_back(1);
            res.push_back(1);
            return res;
        }
        else
        {
            res.push_back(1);
            for(int i = 1; i <= rowIndex/2; ++i)
            {
                if(i==1)
                {
                    res.push_back(rowIndex);
                }
                else
                {
                    long long int num = 1, j=0, k=i;
                    while(j<i)
                    {
                        num*=(rowIndex-j++);
                        if(k>=2 && !(num%k))
                        {
                            num/=k--;
                        }
                    }
                    while(k>=2)
                    {
                        num/=k--;
                    }
                    res.push_back(num);
                }
            }
            vector<int>backupvec(res.begin(), res.end());
            if(!(rowIndex%2))
            {
                backupvec.pop_back();
            }
            res.insert(res.end(), backupvec.rbegin(), backupvec.rend());
            
        }
    }
};

//SECOND TRIAL
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>v1(rowIndex, 1), v2(rowIndex+1, 1);
        if(rowIndex<=1)
            return v2;
        for(int i = 2; i<=rowIndex; ++i)
        {
            for(int j = 1; j<i; ++j)
                v2[j] = v1[j-1] + v1[j];
            v1 = v2;
        }
        return v2;
    }
};
