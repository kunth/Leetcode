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
