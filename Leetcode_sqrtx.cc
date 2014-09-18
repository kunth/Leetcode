//152ms
class Solution {
public:
    int sqrt(int x) {
        if(x<=1)
            return x;
        int i = 2;
        for(; i*i<=x &&i*i>0; ++i)
        {
            if((i+100)*(i+100)>0 &&(i+100)*(i+100)<x)
            {
                i+=100;
            }
        }
        return i-1;
    }
};


//96ms
class Solution {
public:
    int sqrt(int x) {
        if(x<=1)
            return x;
        int i = 2;
        for(; i*i<=x &&i*i>0; ++i)
        {
            if((i+1000)*(i+1000)>0 &&(i+1000)*(i+1000)<x)
            {
                i+=1000;
            }
        }
        return i-1;
    }
};

//348ms
class Solution {
public:
    int sqrt(int x) {
        if(!x || x==1)
            return x;
        long long int ans = 2, y = x;
        while(2) {
            if(ans*ans > y)
                break;
            if(4*ans*ans <= y)
                ans = 2*ans+1;
            else
                ++ans;
        }
        return ans-1;
    }
};
