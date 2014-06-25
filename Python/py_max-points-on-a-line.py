# Definition for a point
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        if not points:return 0
        ans = 0
        slope = 0.0
        for i in points:
            dict = {}
            maxdict = vertical = same = 0
            for j in points:
                if i.x==j.x:
                    if i.y==j.y:
                        same += 1
                    else:
                        vertical += 1
                else:
                    slope = float(j.y-i.y) / (j.x-i.x)
                    if dict.has_key(slope):
                        dict[slope] += 1
                    else:
                        dict[slope] = 1
                    maxdict = max(maxdict, dict[slope])
            ans = max(ans, max(maxdict, vertical)+same)
        return ans
            
