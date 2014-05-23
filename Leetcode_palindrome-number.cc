class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        if(x<10)
        {
            return true;
        }
        int y = x, sum = x%10;
        while(y / 10)
        {
            y /= 10;
            sum = sum*10+y%10;
        }
        return sum==x;
    }
};
