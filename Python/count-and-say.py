class Solution:
    # @return a string
    def countAndSay(self, n):
        s = "1"
        for i in range(1, n):
            ch = s[0]
            cnt = 1
            news = ""
            for j in range(1, len(s)):
                if ch == s[j] :
                    cnt += 1
                else :
                    news += (str(cnt) + ch)
                    ch = s[j]
                    cnt = 1
            news += (str(cnt) + ch)
            s = news
        return s
