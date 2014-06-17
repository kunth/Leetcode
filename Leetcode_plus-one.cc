//http://oj.leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, num = 0;
        vector<int>res;
        for(int i = digits.size()-1; i>=0; --i)
        {
            num = digits[i] + carry;
            if(num>9)
            {
                carry = 1;
                res.push_back(num-10);
            }
            else
            {
                carry = 0;
                res.push_back(num);
            }
        }
            
            if(carry)
                res.push_back(carry);
            
            reverse(res.begin(), res.end());
            return res;
    }
};

//SECOND TRIAL, 12ms
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.empty())
            return digits;
        bool flag = false;
        int sz = digits.size();
        for(int i = 0; i<sz; ++i)
        {
            if(digits[i]!=9)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            vector<int>ans(sz+1, 0);
            ans[0] = 1;
            return ans;
        }
        int carry = 1;
        for(int i = sz-1; i>=0; --i)
        {
            digits[i] += carry;
            if(digits[i]==10)
            {
                digits[i] = 0;
                carry = 1;
            }
            else
                break;
        }
        return digits;
    }
};
