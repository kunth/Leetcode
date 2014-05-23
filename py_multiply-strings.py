#1196ms

class Solution:
    # @param num1, a string
    # @param num2, a string
    # @return a string
    def multiply(self, num1, num2):
        if len(num1) < len(num2):
            tmp = num2
            num2 = num1
            num1 = tmp
        val = carry = 0
        ans = ""
        for i in range(0, len(num1)+len(num2)):
            for j in range(i+1, 0, -1):
                k = i+2-j
                if k>len(num2) or j>len(num1):
                    continue
                val += int(num1[-j]) * int(num2[-k])
            ans += str((val+carry)%10)
            carry = (val+carry)//10
            val = 0
        while carry>0:
            ans += str(carry%10)
            carry /= 10
        while len(ans)>1 and ans[-1]=="0":
            ans = ans[:-1]
        return ans[-1::-1]

