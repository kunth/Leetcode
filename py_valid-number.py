#396ms
class Solution:
    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
        s = s.strip()
        if not s: return False
        try:
            float(s)
        except Exception, e:
            return False
        else:
            return True
            
