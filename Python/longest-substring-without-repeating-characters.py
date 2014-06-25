class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        if not s:
            return 0
        d = {}
        maxlen = i = 0
        for j in range(0, len(s)):
            if not d.has_key(s[j]):
                d[s[j]] = j
            else:
                while s[i] != s[j]:
                    del d[s[i]]
                    i+=1
                i+=1
            maxlen = max(maxlen, j-i+1)
        return maxlen
