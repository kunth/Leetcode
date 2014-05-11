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
