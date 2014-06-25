#stunned for Runtime: 5468 ms

class Solution:
    # @return a string
    def longestPalindrome(self, s):
        if not s or len(s)==1: return s
        longLen = 1
        ans = ""
        for i in range(len(s)):
            j = 1
            while i-j >= 0 and j+i<= len(s)-1 and s[i-j] == s[j+i]:
                j+=1
            if 2*j-1 > longLen:
                longLen = 2*j-1
                ans = s[i-j+1:i+j]

            j = 1
            while i-j>=0 and i+j-1<=len(s)-1 and s[i+j-1]==s[i-j]:
                j+=1
            if 2*j-2 > longLen:
                longLen = 2*j-2
                ans = s[i-j+1:i+j-1]
        
        return ans
