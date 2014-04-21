class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        if(!height.empty())
        {
            int left = 0, right = height.size()-1;
            while(left < right)
            {
                res = max(res, (right - left)*min(height[left], height[right]));
                if(height[left]<height[right])
                    ++left;
                else
                    --right;
            }
        }
        return res;
    }
};
