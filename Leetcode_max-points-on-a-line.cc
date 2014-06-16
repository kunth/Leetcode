/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty())
            return 0;
        unordered_map<double, int>dm;
        int ans = 0, vertical = 0, same = 0, maxdm = 0;
        double dslope = 0.0;
        for(int i = 0; i<points.size(); ++i)
        {
            dm.clear();
            dslope = vertical = same = maxdm = 0;
            for(int j = 0; j<points.size(); ++j)
            {
                if(points[i].x==points[j].x)
                {
                    if(points[i].y==points[j].y)
                        ++same;
                    else
                        ++vertical;
                }
                else
                {
                    dslope = (double)(points[j].y-points[i].y) / (points[j].x-points[i].x);
                    ++dm[dslope];
                    maxdm = max(maxdm, dm[dslope]);
                }
            }
            ans = max(ans, max(vertical, maxdm)+same);
        }
        return ans;
    }
};

//SECOND TRIAL, almost the same
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty())
            return 0;
        else if(points.size()<=2)
            return points.size();
        int same = 0, vertical = 0, slope_cnt = 0, ans = 0;
        float slope;
        unordered_map<float, int>mp;
        for(int i = 0; i<points.size(); ++i)
        {
            same = vertical = slope_cnt = 0;
            mp.clear();
            for(int j = 0; j<points.size(); ++j)
            {
                if(j != i)
                {
                    if(points[j].x == points[i].x)
                    {
                        if(points[j].y==points[i].y)
                            ++same;
                        else
                            ++vertical;
                    }
                    else
                    {
                        slope = float(points[j].y - points[i].y) / (points[j].x - points[i].x);
                        ++mp[slope];
                        if(mp[slope] > slope_cnt)
                            slope_cnt = mp[slope];
                    }
                }
            }
            ans = max(ans, 1+same+max(slope_cnt, vertical));
        }
        return ans;
    }
};
