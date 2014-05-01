#Accepted 208ms
class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        s = {}
        snum = sorted(num)
        i = 0
        j = len(num)-1
        while i < j :
            if snum[i] + snum[j] == target:
                idx_i = num.index(snum[i])
                idx_j = num.index(snum[j])
                if idx_i < idx_j :
                    return (idx_i+1, idx_j+1)
                elif idx_i > idx_j:
                    return (idx_j+1, idx_i+1)
                else:
                    t = [k for k, val in enumerate(num) if val==snum[i]]
                    return (t[0]+1, t[1]+1)
            elif snum[i] + snum[j] < target:
                i += 1
            else:
                j -= 1
                
#Attention: Next is the TLE code:
#I ever used a list and a dictionary, but both of it failed, overtime! So python's dict can't compare with C++'s map?
#TLE:
class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        s = []
        for idx in range(0, len(num)):
            if target - num[idx] in s:
                return tuple((num.index(target-num[idx])+1, idx+1))
            else:
                s.append(num[idx])
