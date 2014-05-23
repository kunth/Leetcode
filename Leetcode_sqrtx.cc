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

