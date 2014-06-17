//http://oj.leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int arr[100];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        for(int i = 3; i <= n; ++i)
        {
            arr[i] = arr[i-1]+arr[i-2];
        }
        
        return arr[n];
    }
};

//SECOND TRIAL
class Solution {
public:
    int climbStairs(int n) {
        if(n<=0)
            return 0;
        int sum = 2;
        vector<int>vec;
        vec.push_back(1);
        while(sum>=0)
        {
            vec.push_back(sum);
            sum = vec[vec.size()-1] + vec[vec.size()-2];
        }
        return vec[n-1];
    }
};
