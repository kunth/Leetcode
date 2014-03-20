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
