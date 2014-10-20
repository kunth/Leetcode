//compare this with Maximal-rectangle
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.empty())
            return 0;
        stack<int>st;
        int pos, ans = 0;
        for(int i = 0; i<height.size(); ++i) {
            while(!st.empty() && height[i] < height[st.top()]) {
                pos = st.top();
                st.pop();
                ans = max(ans, height[pos] * (st.empty() ? i : i-st.top()-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            pos = st.top();
            st.pop();
            ans = max(ans, height[pos] * (int)(st.empty() ? height.size() : height.size()-1-st.top()));
        }
        return ans;
    }
};
