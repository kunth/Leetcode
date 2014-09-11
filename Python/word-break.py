class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        if not s or not len(dict):
            return False
        dp = [True] + [False] * len(s)
        for i in range(len(dp)):
            for word in dict:
                if dp[i] and i+len(word) <= len(s) and s[i:i+len(word)]==word :
                    dp[i+len(word)] = True
            if dp[len(s)]:
                return True
        return False
