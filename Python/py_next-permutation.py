class Solution:
    # @param num, a list of integer
    # @return a list of integer
    def nextPermutation(self, num):
        if not num:
            return num
        for i in range(len(num)-1,0,-1):
            if num[i] > num[i-1]:
                for j in range(len(num)-1,i-1,-1):
                    if num[j] > num[i-1]:
                        num[i-1], num[j] = num[j], num[i-1]
                        break
                return num[:i] + sorted(num[i:])
        return sorted(num)
