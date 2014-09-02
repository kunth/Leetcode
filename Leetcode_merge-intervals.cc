/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
     bool cmp(const Interval&lhs, const Interval&rhs)
    {
        if(lhs.start==rhs.start)
            return lhs.end < rhs.end;
        return lhs.start<rhs.start;
    }
class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval>vec;
        if(intervals.empty())
            return vec;
        sort(intervals.begin(), intervals.end(), cmp);
        vec.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i].start>vec[vec.size()-1].end)
            {
                vec.push_back(intervals[i]);
            }
            else if(intervals[i].end>vec[vec.size()-1].end)
            {
                vec[vec.size()-1].end=intervals[i].end;
            }
        }
        return vec;
    }
};


//Second trial, almost the same

bool predicate(const Interval& lhs, const Interval& rhs) {
    if(lhs.start == rhs.start) {
        return lhs.end < rhs.end;
    }
    return lhs.start < rhs.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if(intervals.empty()) {
            return ans;
        }
        sort(intervals.begin(), intervals.end(), predicate);
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start <= ans.back().end) {
                ans[ans.size()-1].end = max(intervals[i].end, ans.back().end);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
