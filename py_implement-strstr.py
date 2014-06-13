class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def strStr(self, haystack, needle):
        if haystack == needle:
            return needle
        h = len(haystack)
        n = len(needle)
        if not haystack or h < n:
            return None
        if not needle:
            return haystack
        for i in range(0, h-n+1):
            f = True
            for j in range(0, n):
                if haystack[i+j] != needle[j]:
                    f = False
                    break;
            if f:
                return haystack[i:]
        return None

#python的测试集不一样？写成下面的会有错误,这个不应该返回NULL么
#Input: 	"a", ""
#Output: 	null
#Expected: 	"a"

# WA 代码
"""
class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def strStr(self, haystack, needle):
        if haystack == needle:
            return needle
        h = len(haystack)
        n = len(needle)
        if not haystack or not needle or h < n:
            return None
        #if not needle:
        #    return haystack
        for i in range(0, h-n+1):
            f = True
            for j in range(0, n):
                if haystack[i+j] != needle[j]:
                    f = False
                    break;
            if f:
                return haystack[i:]
        return None
"""
