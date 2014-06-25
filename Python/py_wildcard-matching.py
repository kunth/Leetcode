class Solution:
    # @param s, an input string
    # @param p, a pattern string
    # @return a boolean
    def isMatch(self, s, p):
        p += '\0'
        copys = copyp = ""
        flag = True
        while s:
            if s[0] == p[0] or p[0] == '?':
                s = s[1:]
                p = p[1:]
            elif p[0] == '*':
                copyp = p
                copys = s
                p = p[1:]
            elif copyp:
                copys = copys[1:]
                s = copys
                p = copyp[1:]
            else:
                return False

        while p and p[0]=='*':
            p = p[1:]
        return p[0]=='\0'
