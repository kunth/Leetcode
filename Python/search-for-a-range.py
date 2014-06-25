class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        ans = [-1, -1]
        if not A:
            return ans
        left = 0
        right = len(A)-1
        while left <= right:
            mid = (left+right)//2
            if A[mid] > target:
                right = mid - 1;
            elif A[mid] < target:
                left = mid + 1;
            else:
                left = right = mid
                while left>=0 and A[left]==target:
                    left -= 1
                while right<len(A) and A[right]==target:
                    right += 1
                ans = [left+1, right-1]
                break
        return ans
