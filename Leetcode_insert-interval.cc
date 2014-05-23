/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
    static bool cmp(const Interval&lhs, const Interval&rhs)
    {
        if(lhs.start==rhs.start)
            lhs.end<rhs.end;
        return lhs.start<rhs.start;
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), Solution::cmp);
        ans.push_back(intervals[0]);
        for(int i = 1; i<intervals.size(); ++i)
        {
            if(intervals[i].start>ans[ans.size()-1].end)
            {
                ans.push_back(intervals[i]);
            }
            else if(intervals[i].end > ans[ans.size()-1].end)
            {
                ans[ans.size()-1].end = intervals[i].end;
            }
        }
        return ans;
    }
};
