class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        if(x < 0)
        {
            flag = false;
        }
        string str;
        stringstream ss;
        ss << x;
        ss >> str;
        std::reverse(str.begin(), str.end());
        stringstream revss;
        revss << str;
        revss >> x;
        if(flag)
        {
            return x;
        }
        return -x;
    }
};

//SECOND TRIAL
class Solution {
public:
    int reverse(int x) {
        long long int y = x;
        bool f = x >=0 ? true : false;
        if(!f)
            y=-y;
        stringstream ss;
        string str;
        ss << y;
        ss >> str;
        string rs(str.rbegin(), str.rend());
        ss.clear();
        ss.str("");
        ss << rs;
        ss >> y;
        return f ? y : -y;
    }
};
